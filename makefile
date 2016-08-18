prefix=/usr/local
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

install: libs/libmml.a
	cp libs/libmml.a $(prefix)/lib && mkdir -p $(prefix)/include/mml && cp src/*.h $(prefix)/include/mml
    
.PHONY: install

