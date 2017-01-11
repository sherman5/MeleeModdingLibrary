@echo ON

del libmml.a
wiimake-ar -std=c99 libmml.a src\math.c
del src\*.o