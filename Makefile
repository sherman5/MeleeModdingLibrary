# version of library
VERSION = mml-beta

# GNU tools
CC = powerpc-eabi-gcc
AR = powerpc-eabi-ar
OBJCPY = powerpc-eabi-objcopy

# sources and header files (included in distribution)
SRCS = src/math.c src/random.c src/string.c src/system.c src/print.c
HEADERS = $(SRCS:.c=.h) src/melee.h src/melee/melee102.h \
src/melee/meleePAL.h src/melee/fptrs102.h

# object files and their dependencies
OBJS_O0 = $(SRCS:src/%.c=build/%_O0.o)
OBJS_O1 = $(OBJS_O0:%_O0.o=%_O1.o)
OBJS_O2 = $(OBJS_O0:%_O0.o=%_O2.o)
OBJS_O3 = $(OBJS_O0:%_O0.o=%_O3.o)

OBJS = $(OBJS_O0) $(OBJS_O1) $(OBJS_O2) $(OBJS_O3)
DEP = $(OBJS:.o=.d)

# names of the libraries (one for each -O flag)
LIBS = libmml.a libmml_O1.a libmml_O2.a libmml_O3.a

# link, archive, and compile flags
LDFLAGS = 
AFLAGS = -cvr
CFLAGS = -Wall -Wextra -std=c99 -fno-builtin \
-fdata-sections -ffunction-sections

# sections to remove from object files
SECTIONS = .comment

# library targets (need to set optimizer flag)
libmml.a : $(OBJS_O0)
libmml_O1.a : $(OBJS_O1)
libmml_O2.a : $(OBJS_O2)
libmml_O3.a : $(OBJS_O3)

libs : $(LIBS)

# command to build the libraries
%.a : 
	$(AR) $(AFLAGS) $@ $^

# include auto-generated dependencies
-include $(DEP)

# rule to build object files and remove unneccesary sections
build/%_O0.o : src/%.c
	$(CC) $(CFLAGS) -O0 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@

build/%_O1.o : src/%.c
	$(CC) $(CFLAGS) -O1 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@

build/%_O2.o : src/%.c
	$(CC) $(CFLAGS) -O2 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@

build/%_O3.o : src/%.c
	$(CC) $(CFLAGS) -O3 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@

# target for building the distribution
.PHONY : tar zip
dist : | clean_dist libs tar zip

# build the tar.gz version of the distribution
tar : 
	tar --transform='s|src|include/mml|' -czf $(VERSION).tar.gz \
	$(HEADERS) tutorials/ $(LIBS)

# build the .zip version of the distribution
zip : 
	zip $(VERSION).zip -r $(HEADERS) tutorials/ $(LIBS)
	for h in $(HEADERS:src/%.h=%.h) ; do \
		printf "@ src/$$h\n@=include/mml/$$h" | zipnote -w $(VERSION).zip ; \
	done

# test targets
.PHONY : test_math

# iso file to inject test code into

ISO_FILE = Melee.iso

test_math : libmml.a
	wiimake $(ISO_FILE) tests/testMath.ini $(MAKE_FLAGS)

test_string : libmml.a
	wiimake $(ISO_FILE) tests/testString.ini $(MAKE_FLAGS)

test_system : libmml.a
	wiimake $(ISO_FILE) tests/testSystem.ini $(MAKE_FLAGS)

# clean targets
.PHONY : clean clean_libs clean_deps clean_objects clean_dist clean_tests

clean : clean_libs clean_deps clean_objects clean_dist clean_tests

clean_deps :
	rm -f $(DEP)

clean_libs :
	rm -f $(LIBS)

clean_objects :
	rm -f $(OBJS) tests/*.o

clean_dist :
	rm -f $(VERSION).tar.gz $(VERSION).zip

clean_tests : 
	rm -f tests/*.o final.txt *.o *.s linker_script.txt size_linker_script.txt sizes.out sizes.txt final.out


