@echo off
setlocal enabledelayedexpansion

:: Define report file
set REPORT_FILE=%USERPROFILE%\Downloads\Downloads_Report.txt

:: Clear previous report
echo === Downloads Folder Analysis Report === > "%REPORT_FILE%"
echo Generated on: %DATE% %TIME% >> "%REPORT_FILE%"
echo. >> "%REPORT_FILE%"

:: List files with details
for %%F in ("%USERPROFILE%\Downloads\*.*") do (
    echo File: %%~nxF >> "%REPORT_FILE%"
    echo Size: %%~zF bytes >> "%REPORT_FILE%"
    echo Last Modified: %%~tF >> "%REPORT_FILE%"
    echo --------------------------- >> "%REPORT_FILE%"
)

echo Report generated successfully!
exit
