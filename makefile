CC = powerpc-eabi-gcc
AR = powerpc-eabi-ar
CFLAGS = -c
ARFLAGS = -cvr

OBJECTS = build/Controller.o build/MeleeMath.o

libs/libmml.a: $(OBJECTS)
	$(AR) $(ARFLAGS) libs/libmml.a $(OBJECTS)

build/Controller.o: src/Controller.c
	$(CC) $(CFLAGS) src/Controller.c -o build/Controller.o 

build/MeleeMath.o: src/MeleeMath.c
	$(CC) $(CFLAGS) src/MeleeMath.c -o build/MeleeMath.o 

clean:
	rm -f src/*~ build/*.o libs/*.a

