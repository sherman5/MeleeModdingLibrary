@echo OFF
SETLOCAL ENABLEDELAYEDEXPANSION

del libmml.a

@echo ON
wiimake-ar -std=c99 libmml.a src\math\*.c src\random\*.c src\controller\*.c
@echo OFF

del src\math\*.o src\random\*.o src\controller\*.o

