@echo ON
SETLOCAL ENABLEDELAYEDEXPANSION

del libmml.a

wiimake-ar -std=c99 libmml.a src\math\*.c src\random\*.c src\controller\*.c

del src\math\*.o src\random\*.o src\controller\*.o
