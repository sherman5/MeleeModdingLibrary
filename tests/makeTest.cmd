@echo OFF

IF %1.==. GOTO No1
set name=%1

@echo ON
wiimake ../Melee.iso test%name%.ini
@echo OFF

del *.o
GOTO End

:No1
 ECHO Missing test name
:End