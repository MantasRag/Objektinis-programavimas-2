@echo off

REM Sukurti build aplanką, jei jo nėra
if not exist build mkdir build

cd build

REM Generuoti ir kompiliuoti projektą
cmake .. -G "MinGW Makefiles" || (echo CMake konfiguracija nepavyko & cd .. & pause & exit /b 1)
cmake --build . --config Release || (echo Kompiliavimas nepavyko & cd .. & pause & exit /b 1)

cd ..

REM Kopijuoti txt failus, jei yra
if exist *.txt copy *.txt build\ >nul 2>nul

pause
