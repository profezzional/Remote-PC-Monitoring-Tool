@echo off

WHERE git
if %ERRORLEVEL% NEQ 0 (
    echo Git not found, submodules cannot be initialized
    exit /B
) else (
    echo Initializing submodules
    git submodule init
    git submodule update
)

REM Get the current directory
set currentPath=%cd%


:BuildServer
rem choice /C YN /M "Build Server?"
rem if %ERRORLEVEL% NEQ 1 (
rem     goto BuildApp
rem )

echo Building Server

REM Hardcode some paths to MSBuild.exe
SET msbuildpath="C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe"
if exist %msbuildpath% (
    goto msBuildFound
)

SET msbuildpath="C:/Program Files (x86)/Microsoft Visual Studio/2019/Preview/MSBuild/Current/Bin/MSBuild.exe"
if exist %msbuildpath% (
    goto msBuildFound
)

goto msBuildNotFound

:msBuildNotFound
echo Error, MSBuild not found, ensure you have VS2019 isntalled.
exit /B

:msBuildFound
REM echo out where MSBuild was located at
echo MSBuild Found at:
echo %msbuildpath%



REM Set up the project path
set slnPath=%currentPath%\Remote-PC-Monitoring-Tool\Remote-PC-Monitoring-Tool.sln
echo solution Found at:

echo %slnPath%
REM Set the configuration to release x64, only build the 'Server' project

REM Execute MSBuild
%msbuildpath% "%slnPath%" /t:Server /p:Configuration=Release /p:Platform="x64" /p:BuildProjectReferences=false

REM All is done
echo Build script finished, output file:
echo %currentPath%\bin\Server.exe


:BuildApp
rem choice /C YN /M "Build Mobile App?"
rem if %ERRORLEVEL% NEQ 1 (
rem     goto End
rem )
echo Building Mobile App


WHERE npm
if %ERRORLEVEL% NEQ 0 (
    echo npm not found, please install it to build the app
    exit /B
)

WHERE node
if %ERRORLEVEL% NEQ 0 (
    echo nativescript not found, please install it to build the app
    exit /B
)

REM tns can optionally install the android sdk, java, and even a VM/emulator if you want.  Plus it'll copy the .apk file for us
tns build android --path Remote-PC-Monitoring-Tool\mobile-app --copy-to bin

:End
echo Script completed
pause
exit /B