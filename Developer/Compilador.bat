@echo off
set Nome_Do_Projeto="Hub_Programacao"

tasklist | findstr %Nome_Do_Projeto%.exe && taskkill /F /IM %Nome_Do_Projeto%.exe

cls

cd Developer

xcopy "data" "backup\"  /Q /E /I /Y

xcopy "img\Aplication_Images" "..\output\Aplication_Images\" /Q /E /I /Y
xcopy "models" "..\output\models\" /Q /E /I /D /Y
xcopy "data" "..\output\data\" /Q /E /I /Y
xcopy "backup" "..\output\backup\" /Q /E /I /Y

cls

windres config/resources.rc -O coff -o config/resources.res

@REM gcc -o ../output/%Nome_Do_Projeto% main.cpp src/*.cpp modules/*.cpp config/resources.res -I include %gtk_cflags% %gtk_libs% -lstdc++ -mwindows
gcc -o ../output/%Nome_Do_Projeto% main.cpp src/*.cpp modules/*.cpp config/resources.res -I include %gtk_cflags% %gtk_libs% -lstdc++ 

cd config

del resources.res

cd ../

cd ../output

%Nome_Do_Projeto%.exe