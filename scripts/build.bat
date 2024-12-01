@echo off

REM Create build directory if it doesn't exist
mkdir build
cd build

REM Run CMake to configure the project
cmake ..

REM Build the project
cmake --build .

REM Copy resources
xcopy /e /i ..\memogeister_rep\resources\ .\bin\resources\

REM Run the game
.\bin\MEMOGEISTER.exe