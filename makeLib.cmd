@echo ON

wiimake-ar -std=c99 libmml.a src\random.c src\math.c src\malloc.c
del src\*.o