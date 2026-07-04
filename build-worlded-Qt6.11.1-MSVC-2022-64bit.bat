call "D:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64
mkdir C:\Programming\PZWorldEd\dist64
cd C:\Programming\PZWorldEd\dist64
"C:\Programming\QtSDK2015\6.11.1\msvc2022_64\bin\qmake.exe" "C:\Users\Walter\Desktop\WorldEdb42\PZWorldEd.pro" -r -spec win32-msvc "CONFIG+=release"
"C:\Programming\QtSDK2015\Tools\QtCreator\bin\jom\jom.exe"
PAUSE
