@echo OFF
where make > nul
if not %ERRORLEVEL% == 0 goto NOMAKE
make
if not %ERRORLEVEL% == 0 pause
goto EOF
:NOMAKE
echo Make not found
:EOF
