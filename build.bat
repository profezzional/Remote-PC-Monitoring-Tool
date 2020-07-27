python --version 2>NUL
if errorlevel 1 goto error
python scripts\build.py
goto:eof
:errorNoPython
echo Python does not appear to be installed, looks like you'll have to compile manually.
