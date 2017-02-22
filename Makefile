# version of library
MAJOR = 1
MINOR = 0
REVISION = 0
VERSION = mml-$(MAJOR).$(MINOR).$(REVISION)

# GNU tools
CC = powerpc-eabi-gcc
AR = powerpc-eabi-ar
OBJCPY = powerpc-eabi-objcopy

# sources and header files (included in distribution)
SRCS = src/AI.c src/controller.c src/game_state.c src/inputs.c \
src/math.c src/print.c src/random.c src/state_check.c \
src/string.c src/system.c src/melee_info.c src/version.c

HEADERS = $(SRCS:.c=.h) src/gctypes.h src/native_functions.h \
src/unit_test.h src/logic.h

# object files and their dependencies
OBJS_O0 = $(SRCS:src/%.c=build/%_O0.o)
OBJS_O1 = $(OBJS_O0:%_O0.o=%_O1.o)
OBJS_O2 = $(OBJS_O0:%_O0.o=%_O2.o)
OBJS_O3 = $(OBJS_O0:%_O0.o=%_O3.o)
OBJS_Os = $(OBJS_O0:%_O0.o=%_Os.o)
OBJS_PAL = $(OBJS_O0:%_O0.o=%_PAL.o)

OBJS = $(OBJS_O0) $(OBJS_O1) $(OBJS_O2) $(OBJS_O3) $(OBJS_Os) $(OBJS_PAL)
DEP = $(OBJS:.o=.d)

# names of the libraries (one for each -O flag)
LIBS = libmml.a libmml_O1.a libmml_O2.a libmml_O3.a libmml_Os.a \
#libmml_PAL.a

# link, archive, and compile flags
LDFLAGS = 
AFLAGS = -cvr
CFLAGS = -Wall -Wextra -std=c99 -fno-builtin \
-fdata-sections -ffunction-sections \
-DMAJOR=$(MAJOR) -DMINOR=$(MINOR) -DREVISION=$(REVISION)

# sections to remove from object files
SECTIONS = .comment

# library targets (need to set optimizer flag)
libmml.a : $(OBJS_O0) 
libmml_O1.a : $(OBJS_O1)
libmml_O2.a : $(OBJS_O2)
libmml_O3.a : $(OBJS_O3) 
libmml_Os.a : $(OBJS_Os) 
libmml_PAL.a : $(OBJS_PAL)

$(OBJS_O0) : | build_dir
$(OBJS_O1) : | build_dir
$(OBJS_O2) : | build_dir
$(OBJS_O3) : | build_dir
$(OBJS_Os) : | build_dir
$(OBJS_PAL) : | build_dir

.PHONY : build_dir
build_dir : 
	mkdir -p build

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
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_O1.o : src/%.c
	$(CC) $(CFLAGS) -O1 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_O2.o : src/%.c
	$(CC) $(CFLAGS) -O2 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_O3.o : src/%.c
	$(CC) $(CFLAGS) -O3 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_Os.o : src/%.c
	$(CC) $(CFLAGS) -Os -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_PAL.o : src/%.c
	$(CC) $(CFLAGS) -O1 -DPAL -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

# target for building the distribution
.PHONY : tar zip
dist : | clean_dist libs tar zip untar

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

# extract dist to folder
untar : 
	mkdir -p $(VERSION)
	tar -xf $(VERSION).tar.gz -C $(VERSION)

# test targets
.PHONY : test_controller test_gamestate test_inputs test_math \
test_player test_print test_random test_string test_system

# iso file to inject test code into

ISO_FILE = Melee.iso

test_ai : $(LIBS)
	wiimake $(ISO_FILE) tests/testAI.ini $(MAKE_FLAGS)

test_controller : $(LIBS)
	wiimake $(ISO_FILE) tests/testController.ini $(MAKE_FLAGS)

test_game_state : $(LIBS)
	wiimake $(ISO_FILE) tests/testGameState.ini $(MAKE_FLAGS)

test_inputs : $(LIBS)
	wiimake $(ISO_FILE) tests/testInputs.ini $(MAKE_FLAGS)

test_math : $(LIBS)
	wiimake $(ISO_FILE) tests/testMath.ini $(MAKE_FLAGS)

test_melee_info : $(LIBS)
	wiimake $(ISO_FILE) tests/testMeleeInfo.ini $(MAKE_FLAGS)

test_print : $(LIBS)
	wiimake $(ISO_FILE) tests/testPrint.ini $(MAKE_FLAGS)

test_random : $(LIBS)
	wiimake $(ISO_FILE) tests/testRandom.ini $(MAKE_FLAGS)

test_state_check : $(LIBS)
	wiimake $(ISO_FILE) tests/testStateCheck.ini $(MAKE_FLAGS)

test_string : $(LIBS)
	wiimake $(ISO_FILE) tests/testString.ini $(MAKE_FLAGS)

test_system : $(LIBS)
	wiimake $(ISO_FILE) tests/testSystem.ini $(MAKE_FLAGS)

# tutorial targets
.PHONY : tutorial_SimpleTestProgram

tutorial_SimpleTestProgram : dist
	cd $(VERSION)/tutorials/SimpleTestProgram && \
	wiimake ../../../$(ISO_FILE) SimpleTestProgram.ini $(MAKE_FLAGS) && \
	cd ../../..

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
	rm -rf  $(VERSION)

clean_tests : 
	rm -f tests/*.o final.txt *.o *.s linker_script.txt \
	size_linker_script.txt sizes.out sizes.txt final.out


