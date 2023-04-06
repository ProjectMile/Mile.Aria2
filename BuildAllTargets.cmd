@setlocal
@echo off

rem Change to the current folder.
cd "%~dp0"

rem Remove the output folder for a fresh compile.
rd /s /q Output

rem Initialize Visual Studio environment
call "%~dp0Mile.Project.Windows\InitializeVisualStudioEnvironment.cmd"

rem Build all targets
MSBuild -binaryLogger:Output\BuildAllTargets.binlog -m BuildAllTargets.proj

rem Extract files from NuGet package to folder
7z x Output\Mile.Aria2.nupkg "-o.\Output\Mile.Aria2"
if %ERRORLEVEL% NEQ 0 exit /B %ERRORLEVEL%

rem Copy Documents
copy .\Output\Mile.Aria2\*.md .\Output\Mile.Aria2\Redist\
rename .\Output\Mile.Aria2\Redist\*.md *.txt
if %ERRORLEVEL% NEQ 0 exit /B %ERRORLEVEL%

rem Build SDK Package
7z a -r Output\Mile.Aria2.zip .\Output\Mile.Aria2\Redist\*.*


@endlocal