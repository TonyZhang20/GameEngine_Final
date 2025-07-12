rem for %%I in (.) do set CurrDirName=%%~dpI
REM SETX AZUL_PATH 12

// Set the current directory
for %%I in (.) do set CurrDirName=%%~fI
echo %CurrDirName%

SETX AZUL_PATH "%CurrDirName%"
