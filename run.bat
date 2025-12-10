@echo off
echo      PALEIDZIAMA STUDENTU SISTEMA
echo.

REM Patikrinti ar build katalogas egzistuoja
if not exist build (
    echo [KLAIDA] Build katalogas nerastas
    echo Pirmiausia paleiskite: build.bat
    pause
    exit /b 1
)

REM Patikrinti ar .exe failas egzistuoja
if not exist build\Studentu_Sistema.exe (
    echo [KLAIDA] Vykdomasis failas nerastas
    echo Pirmiausia paleiskite: build.bat
    pause
    exit /b 1
)

cd build
echo Paleidziama programa...
echo.
echo.

Studentu_Sistema.exe
cd ..
pause