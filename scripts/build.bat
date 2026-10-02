@echo off
rem ---------------------------------------------------------------------------
rem Сборка лабораторной работы, вариант 8 "Кафе" (MSVC, Visual Studio).
rem Использование: scripts\build.bat
rem ---------------------------------------------------------------------------
setlocal

set "ROOT=%~dp0.."
set "OUT=%ROOT%\build"

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
set "VSPATH="
if exist "%VSWHERE%" (
    for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSPATH=%%i"
)

if not defined VSPATH (
    echo [ERROR] Visual Studio with C++ components not found.
    exit /b 1
)

call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" >nul
if errorlevel 1 (
    echo [ERROR] Failed to initialise the MSVC environment.
    exit /b 1
)

if not exist "%OUT%" mkdir "%OUT%"

echo Compiling task1_discount.cpp ...
cl /nologo /EHsc /std:c++17 /W4 /utf-8 /Fo:"%OUT%\\" /Fe:"%OUT%\task1_discount.exe" "%ROOT%\src\task1_discount.cpp"
if errorlevel 1 exit /b 1

echo Compiling task2_service_fee.cpp ...
cl /nologo /EHsc /std:c++17 /W4 /utf-8 /Fo:"%OUT%\\" /Fe:"%OUT%\task2_service_fee.exe" "%ROOT%\src\task2_service_fee.cpp"
if errorlevel 1 exit /b 1

echo Compiling task3_menu.cpp ...
cl /nologo /EHsc /std:c++17 /W4 /utf-8 /Fo:"%OUT%\\" /Fe:"%OUT%\task3_menu.exe" "%ROOT%\src\task3_menu.cpp"
if errorlevel 1 exit /b 1

echo Compiling task4_order.cpp ...
cl /nologo /EHsc /std:c++17 /W4 /utf-8 /Fo:"%OUT%\\" /Fe:"%OUT%\task4_order.exe" "%ROOT%\src\task4_order.cpp"
if errorlevel 1 exit /b 1

echo.
echo [OK] Executables are in the build\ folder:
dir /b "%OUT%\*.exe"
endlocal