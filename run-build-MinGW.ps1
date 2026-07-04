$logFile = "C:\Users\Walter\Desktop\WorldEdb42\build.log"
Remove-Item $logFile -ErrorAction SilentlyContinue
cmd /c "`"C:\Users\Walter\Desktop\WorldEdb42\build-worlded-Qt6.11.1-MinGW-64bit.bat`"" 2>&1 | Tee-Object -FilePath $logFile
Write-Host "`nBuild terminado. Log guardado en: $logFile" -ForegroundColor Cyan
