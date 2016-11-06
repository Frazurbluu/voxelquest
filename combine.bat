cd c:\wamp\www\voxelquest
echo cleaning files
del /q .\compiled\*.*
del /q .\temp\*.*

:: -----------------------------------
echo copying files to source
:: -----------------------------------

xcopy /s /y .\src\cpp .\temp
cd temp

:: -----------------------------------
echo running lzz
:: -----------------------------------

set /a totalhpp=0;
for %%f in (*.hpp) do (
	lzz -hx e -sx h %%f
	set /a totalhpp+=1
)


:: -----------------------------------
echo tot hpp
echo %totalhpp%
echo copying headers to one file
:: -----------------------------------


copy /b .\*.e .\f00270_headers.h
set /a totale=0;
for %%f in (*.e) do (
	set /a totale+=1
	echo. > %%f
)

:: -----------------------------------
echo tot e
echo %totale%
:: -----------------------------------

@echo off
if %totale% == %totalhpp% (
    echo .
) else (
	start "" cmd /c "echo.  Error with LZZ check console output.&echo(&pause"
)

for %%f in (*.h) do (
	echo. >> %%f
)
cd ..

:: -----------------------------------
echo copying files to compiled
:: -----------------------------------

xcopy /s /y .\temp\*.e .\compiled
copy /b .\temp\*.h .\compiled\main.cpp
