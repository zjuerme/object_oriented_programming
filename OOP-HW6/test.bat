@echo off
mingw32-make
if errorlevel 1 exit /b %errorlevel%
echo.
echo Running the Vector Test...
VectorTest.exe
echo.
echo Press any key to exit...
pause >nul