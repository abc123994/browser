rmdir /S /Q  dev
mkdir dev
set Qt=C:\Qt\6.4.2-64
set PATH=%PATH%;%Qt%;
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cd dev & cmake ..\src