CC = powerpc-eabi-gcc
AR = powerpc-eabi-ar
CFLAGS = -c
ARFLAGS = -cvq

OBJECTS = build/Controller.o build/MeleeMath.o

libmml.a: $(OBJECTS)
	$(AR) $(ARFLAGS) libmml.a $(OBJECTS)

build/Controller.o: src/Controller.c
	$(CC) $(CFLAGS) src/Controller.c -o build/Controller.o 

build/MeleeMath.o: src/MeleeMath.c
	$(CC) $(CFLAGS) src/MeleeMath.c -o build/MeleeMath.o 

clean:
	rm src/*~ build/*.o libs/*.a

