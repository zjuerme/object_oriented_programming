@echo off

echo Creating a new diary entry 
Add.exe diary1.txt
pause

echo Creating a new diary entry 
Add.exe diary2.txt
pause

echo Creating a new diary entry
Add.exe diary3.txt
pause

echo Listing all diary entries:
List.exe
pause

echo Listing diary entries between 2023-05-01 and 2023-05-02:
List.exe 2023-05-01 2023-05-02
pause

echo Showing diary entry for 2023-05-07:
Show.exe 2023-05-07
pause

echo Showing diary entry for 2023-05-09:
Show.exe 2023-05-09
pause

echo Removing diary entry for 2023-05-01:
Remove.exe 2023-05-01
pause

echo Listing all diary entries after removal:
List.exe
pause

echo Done.
