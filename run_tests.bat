@echo off

REM PAtikrinama ar build katalogas egzistuoja
if not exist build (
    echo [KLAIDA] Build katalogas nerastas
    echo Pirmiausia paleiskite: build.bat
    pause
    exit /b 1
)

cd build

REM Studentas klasės testai
if exist test_studentas.exe (
    echo.
    echo Testuojama studentas kalsė:
    echo.
    test_studentas.exe
    echo.
) else (
    echo [KLAIDA] test_studentas.exe nerastas!
    echo Paleiskite: build.bat
)

REM Zmogus klasės testai
if exist test_zmogus.exe (
    echo.
    echo Testuojama zmogus klasė:
    echo.
    test_zmogus.exe
    echo.
) else (
    @REM echo [KLAIDA] test_zmogus.exe nerastas
    @REM echo Paleiskite: build.bat
)

cd ..

echo.
echo Visi testai baigti.
echo.
echo Jei visi testai [PASSED] - viskas veikia teisingai!
echo Jei yra [FAILED] - reikia pataisyti klaidas.
echo.
pause