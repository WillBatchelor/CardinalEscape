@echo off
set /p filename= Please enter filename to compile:
C:\Users\Will\.vscode\extensions\ms-vscode.csharp-1.16.1\.omnisharp\1.32.5\msbuild\15.0\Bin\Roslyn\csc.exe %filename%
echo Finished compiling
pause
exit