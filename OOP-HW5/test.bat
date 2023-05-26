@echo off
echo Compiling the Fraction project...
mingw32-make
pause

echo.
echo Running the Fraction program...
echo Test case 1: 6/11 and 9/7
echo.
main.exe 6 11 9 7
echo.
pause

echo Test case 2: -11/7 and 7/11
echo.
main.exe -11 7 7 11
echo.
pause

echo Test case 3: 11/7 and -13/5
echo.
main.exe 11 7 -13 5
echo.
pause

echo Test case 4: 0/1 and 1/0
echo.
main.exe 0 1 1 0
echo.
pause

echo Test case 5: 1/2 and -1/2
echo.
main.exe 1 2 -1 2
echo.
pause

echo Test case 6: Tpye Your Input!
echo.
echo The case will be: numerator1/denominator1, numerator2/denominator2
echo Please enter 4 numbers (numerator1, denominator1, numerator2, and denominator2) separated by spaces:
set /p input="Enter the numbers: "
main.exe %input%
pause

echo Test case 7: Typecast to double 
echo To string 
echo Inserter and extractor streams
echo Please enter 2 numbers (numerator and denominator) separated by spaces:
set /p input="Enter the numbers: "
main.exe %input%
pause

echo Test case 8: Conversion from a finite decimal string(ie, 1.414)
echo.
set /p input="Enter the decimal number: "
main.exe %input%
pause