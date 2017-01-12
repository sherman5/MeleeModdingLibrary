@echo OFF
SETLOCAL ENABLEDELAYEDEXPANSION
set VERSION=1.0.0

if exist release rmdir /s /q release
mkdir release
mkdir release\include\mml

xcopy src\*.h release\include\mml\
xcopy /s src\melee release\include\mml\melee\
xcopy /s tutorials release\tutorials\

CALL makeLib.cmd

xcopy libmml.a release\
