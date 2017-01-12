@echo OFF

set name=%1

@echo ON
wiimake ../Melee.iso test%name%.ini
@echo OFF

del *.o

