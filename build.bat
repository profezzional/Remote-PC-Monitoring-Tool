@echo off

WHERE git
if %ERRORLEVEL% NEQ 0 (
    echo Git not found, submodules will not be initialized
    pause
) else (
    echo Initializing submodules
    git submodule init
    git submodule update
)


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

REM Get the current directory
set currentPath=%cd%

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
