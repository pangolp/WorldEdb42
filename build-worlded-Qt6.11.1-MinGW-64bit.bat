set PATH=C:\Programming\QtSDK2015\Tools\mingw1310_64\bin;%PATH%
if not exist "C:\Programming\PZWorldEd\dist64" mkdir "C:\Programming\PZWorldEd\dist64"
cd C:\Programming\PZWorldEd\dist64
"C:\Programming\QtSDK2015\6.11.1\mingw_64\bin\qmake.exe" "C:\Users\Walter\Desktop\WorldEdb42\PZWorldEd.pro" -r -spec win32-g++ "CONFIG+=release"
"C:\Programming\QtSDK2015\Tools\mingw1310_64\bin\mingw32-make.exe" -j4
