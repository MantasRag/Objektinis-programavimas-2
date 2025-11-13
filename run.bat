@echo off

REM Patikrinti ar build katalogas egzistuoja
if not exist build (
    echo [KLAIDA] Build katalogas nerastas!
    echo Pirmiausia paleiskite: build.bat
    echo.
    pause
    exit /b 1
)

REM Patikrinti ar .exe failas egzistuoja
if not exist build\Studentai_v1.exe (
    echo [KLAIDA] Vykdomasis failas nerastas!
    echo Pirmiausia paleiskite: build.bat
    echo.
    pause
    exit /b 1
)

REM Pereiti į build katalogą ir paleisti
cd build
echo.
Studentai_v1.exe
echo.
cd ..
pause