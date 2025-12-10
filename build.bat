@echo off

REM Patikrinti ar CMake įdiegtas
where cmake >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [KLAIDA] CMake nerastas! Prasome ji idiegti.
    echo Atsisiusti: https://cmake.org/download/
    pause
    exit /b 1
)

REM Patikrinti ar MinGW įdiegtas
where g++ >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [KLAIDA] MinGW kompiliatorius nerastas!
    echo Prasome idiegti MinGW-w64.
    pause
    exit /b 1
)

REM Sukurti build katalogą
if not exist build (
    echo [INFO] Kuriamas build katalogas...
    mkdir build
)

REM Sukurti tests katalogą (jei neegzistuoja)
if not exist tests (
    echo [INFO] Kuriamas tests katalogas...
    mkdir tests
    echo [PERSPĖJIMAS] Prasome įdėti test_studentas.cpp ir test_zmogus.cpp į tests\ katalogą!
)

cd build

REM [1/4] Generuoti build failus
echo.
echo [1/4] Generuojami CMake failai...
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
if %ERRORLEVEL% NEQ 0 (
    echo [KLAIDA] CMake konfiguracija nepavyko!
    cd ..
    pause
    exit /b 1
)

REM [2/4] Kompiliuoti pagrindinę programą
echo.
echo [2/4] Kompiliuojama pagrindine programa...
cmake --build . --config Release --target Studentu_Sistema
if %ERRORLEVEL% NEQ 0 (
    echo [KLAIDA] Pagrindinės programos kompiliavimas nepavyko!
    cd ..
    pause
    exit /b 1
)

REM [3/4] Kompiliuoti Unit testus
echo.
echo [3/4] Kompiliuojami Unit testai...
cmake --build . --config Release --target test_studentas
cmake --build . --config Release --target test_zmogus
if %ERRORLEVEL% NEQ 0 (
    echo [PERSPĖJIMAS] Unit testų kompiliavimas nepavyko!
    echo Patikrinkite ar tests\ kataloge yra test_studentas.cpp ir test_zmogus.cpp
)

REM [4/4] Kopijuoti .txt failus
cd ..
if exist *.txt (
    echo.
    echo [4/4] Kopijuojami .txt failai...
    copy *.txt build\ >nul 2>nul
)

echo.
echo Sukurti failai:
echo   - Pagrindine programa: build\Studentu_Sistema.exe
echo   - Unit testai:         build\test_studentas.exe
echo   - Unit testai:         build\test_zmogus.exe
echo.
echo Paleisti programa:     run.bat
echo Paleisti testus:       run_tests.bat
echo.
pause