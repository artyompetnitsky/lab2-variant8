@echo off
rem ---------------------------------------------------------------------------
rem Тестовые прогоны заданий 1-4.
rem Использование: scripts\run_tests.bat   (сначала выполните scripts\build.bat)
rem Внимание: в строках echo нельзя использовать символ '>' - cmd считает его
rem перенаправлением вывода.
rem ---------------------------------------------------------------------------
setlocal

set "ROOT=%~dp0.."
set "T1=%ROOT%\build\task1_discount.exe"
set "T2=%ROOT%\build\task2_service_fee.exe"
set "T3=%ROOT%\build\task3_menu.exe"
set "T4=%ROOT%\build\task4_order.exe"

if not exist "%T1%" (
    echo [ERROR] %T1% not found. Run scripts\build.bat first.
    exit /b 1
)

echo ================= TASK 1: discount =================
echo.
echo --- cost 20, not student - discount 0 percent, total 20 ---
echo 20 0 | "%T1%"
echo.
echo --- cost 30, not student - discount 5 percent, total 28.5 ---
echo 30 0 | "%T1%"
echo.
echo --- cost 45, student - discount 7 percent beats 5, total 41.85 ---
echo 45 1 | "%T1%"
echo.
echo --- cost 60, student - discount 10 percent beats 7, total 54 ---
echo 60 1 | "%T1%"
echo.
echo --- cost -5 - error ---
echo -5 0 | "%T1%"

echo.
echo ================= TASK 2: service fee =================
echo.
echo --- dishes 50, 2 persons, at table - fee 5, total 55 ---
echo 50 2 1 | "%T2%"
echo.
echo --- dishes 20, 2 persons, at table - fee is the minimum 2, total 22 ---
echo 20 2 1 | "%T2%"
echo.
echo --- dishes 100, 4 persons, at table - fee halved, total 105 ---
echo 100 4 1 | "%T2%"
echo.
echo --- dishes 250, 3 persons, at table - fee 12.5, total 262.5 ---
echo 250 3 1 | "%T2%"
echo.
echo --- dishes 120, 2 persons, takeaway - fee 0, total 120 ---
echo 120 2 0 | "%T2%"
echo.
echo --- persons 0 - error ---
echo 50 0 1 | "%T2%"

echo.
echo ================= TASK 3: menu =================
echo.
echo --- M 1 portion - no discount, total 9 ---
echo M 1 | "%T3%"
echo.
echo --- S 4 portions - no discount, total 24 ---
echo S 4 | "%T3%"
echo.
echo --- D 5 portions - discount 8 percent, total 18.4 ---
echo D 5 | "%T3%"
echo.
echo --- M 20 portions - discount 8 percent, total 165.6 ---
echo M 20 | "%T3%"
echo.
echo --- code X - error ---
echo X 3 | "%T3%"
echo.
echo --- portions 21 - error ---
echo M 21 | "%T3%"

echo.
echo ================= TASK 4: order =================
echo.
echo --- M 2, not student, delivery - no discount, dish 18, delivery 5, total 23 ---
echo M 2 0 1 | "%T4%"
echo.
echo --- M 5, not student, delivery - discount 8 percent, dish 41.4, delivery 5, total 46.4 ---
echo M 5 0 1 | "%T4%"
echo.
echo --- S 10, student, no delivery - discount 10 percent, total 54 ---
echo S 10 1 0 | "%T4%"
echo.
echo --- M 6, student, delivery - 54 minus 10 percent = 48.6, below 50, so delivery is 5 ---
echo M 6 1 1 | "%T4%"
echo.
echo --- M 20, not student, delivery - 165.6 is 50 or more, so delivery is free ---
echo M 20 0 1 | "%T4%"
echo.
echo --- code Q - error ---
echo Q 3 0 1 | "%T4%"
echo.
echo --- portions 25 - error ---
echo M 25 0 1 | "%T4%"
endlocal