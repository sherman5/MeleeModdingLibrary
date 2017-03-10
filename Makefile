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
SRCS = src/ai.c src/controller.c src/game_state.c src/moves.c \
src/math.c src/print.c src/random.c src/state_check.c \
src/string.c src/system.c src/melee_info.c src/version.c src/error.c

HEADERS = $(SRCS:.c=.h) src/gctypes.h src/native_functions.h \
src/unit_test.h src/logic.h src/action_state.h

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
LIBS = libmml.a libmml_O1.a libmml_O2.a libmml_O3.a libmml_Os.a
DIST_LIBS = libmml.a libmml_O1.a libmml_O2.a libmml_O3.a 

DIST_TARGETS = $(HEADERS) $(DIST_LIBS) tutorials/*/*.c tutorials/*/*.h \
tutorials/*/*.ini 

# link, archive, and compile flags
LDFLAGS = 
AFLAGS = -cvr
CFLAGS = -Wall -Wextra -std=c99 -fno-builtin \
-fdata-sections -ffunction-sections -Werror \
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

libs : $(LIBS)

# command to build the libraries
%.a : 
	$(AR) $(AFLAGS) $@ $^

# include auto-generated dependencies
-include $(DEP)

# rule to build object files and remove unneccesary sections
build/%_O0.o : src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -O0 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_O1.o : src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -O1 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_O2.o : src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -O2 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_O3.o : src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -O3 -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_Os.o : src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -Os -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

build/%_PAL.o : src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -O1 -DPAL -c -MMD $< -o $@
	$(OBJCPY) -R $(SECTIONS) $@
	$(OBJCPY) --rename-section .rodata=$*.rodata $@
	$(OBJCPY) --rename-section .gnu.attributes=$*.gnu.attributes $@

# target for building the distribution
.PHONY : dist tar zip untar
dist : libs
	$(MAKE) clean_dist
	$(MAKE) tar
	$(MAKE) untar

# build the tar.gz version of the distribution
tar : 
	tar --transform='s|src|include/mml|' -czf $(VERSION).tar.gz \
	$(DIST_TARGETS)

# build the .zip version of the distribution
zip : 
	zip $(VERSION).zip -r $(DIST_TARGETS)
	for h in $(HEADERS:src/%.h=%.h) ; do \
	  printf "@ src/$$h\n@=include/mml/$$h" | zipnote -w $(VERSION).zip ; \
	done

# extract dist to folder
untar : 
	mkdir -p $(VERSION)
	tar -xf $(VERSION).tar.gz -C $(VERSION)

# test targets
.PHONY : test_ai test_controller test_error test_game_state test_math \
test_melee_info test_moves test_print test_random test_state_check \
test_string test_system test_version

# iso file to inject test code into

ISO_FILE = Melee.iso

test_ai : $(LIBS)
	wiimake $(ISO_FILE) tests/testAI.ini $(MAKE_FLAGS)

test_controller : $(LIBS)
	wiimake $(ISO_FILE) tests/testController.ini $(MAKE_FLAGS)

test_error : $(LIBS)
	wiimake $(ISO_FILE) tests/testError.ini $(MAKE_FLAGS)

test_game_state : $(LIBS)
	wiimake $(ISO_FILE) tests/testGameState.ini $(MAKE_FLAGS)

test_math : $(LIBS)
	wiimake $(ISO_FILE) tests/testMath.ini $(MAKE_FLAGS)

test_melee_info : $(LIBS)
	wiimake $(ISO_FILE) tests/testMeleeInfo.ini $(MAKE_FLAGS)

test_moves : $(LIBS)
	wiimake $(ISO_FILE) tests/testMoves.ini $(MAKE_FLAGS)

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

test_version : $(LIBS)
	wiimake $(ISO_FILE) tests/testVersion.ini $(MAKE_FLAGS)

# tutorial targets
.PHONY : tutorial_SimpleProgram tutorial_Teching tutorial_DI \
tutorial_Recovery tutorial_DefensiveAI tutorial_data

TUTORIALS = tutorial_SimpleProgram tutorial_Teching tutorial_DI \
tutorial_Recovery tutorial_DefensiveAI

tutorial_data : $(TUTORIALS)
	cp $(VERSION)/tutorials/SimpleProgram/SimpleProgram.data \
		tutorials/SimpleProgram/SimpleProgram.data && \
	cp $(VERSION)/tutorials/Teching/TechingTutorial.data \
		tutorials/Teching/TechingTutorial.data && \
	cp $(VERSION)/tutorials/DI/DITutorial.data \
		tutorials/DI/DITutorial.data && \
	cp $(VERSION)/tutorials/Recovery/RecoveryTutorial.data \
		tutorials/Recovery/RecoveryTutorial.data && \
	cp $(VERSION)/tutorials/DefensiveAI/DefensiveAI.data \
		tutorials/DefensiveAI/DefensiveAI.data

tutorial_SimpleProgram : dist
	cd $(VERSION)/tutorials/SimpleProgram && \
	wiimake ../../../$(ISO_FILE) SimpleProgram.ini $(MAKE_FLAGS) && \
	wiimake-isotool ../../../$(ISO_FILE) --save SimpleProgram.data && \
	cd ../../..

tutorial_Teching : dist
	cd $(VERSION)/tutorials/Teching && \
	wiimake ../../../$(ISO_FILE) TechingTutorial.ini $(MAKE_FLAGS) && \
	wiimake-isotool ../../../$(ISO_FILE) --save TechingTutorial.data && \
	cd ../../..

tutorial_DI : dist
	cd $(VERSION)/tutorials/DI && \
	wiimake ../../../$(ISO_FILE) DITutorial.ini $(MAKE_FLAGS) && \
	wiimake-isotool ../../../$(ISO_FILE) --save DITutorial.data && \
	cd ../../..

tutorial_Recovery : dist
	cd $(VERSION)/tutorials/Recovery && \
	wiimake ../../../$(ISO_FILE) RecoveryTutorial.ini $(MAKE_FLAGS) && \
	wiimake-isotool ../../../$(ISO_FILE) --save RecoveryTutorial.data && \
	cd ../../..

tutorial_DefensiveAI : dist
	cd $(VERSION)/tutorials/DefensiveAI && \
	wiimake ../../../$(ISO_FILE) DefensiveAI.ini $(MAKE_FLAGS) && \
	wiimake-isotool ../../../$(ISO_FILE) --save DefensiveAI.data && \
	cd ../../..

# documentation target
.PHONY : docs
docs :
	echo "PROJECT_NUMBER =" $(MAJOR).$(MINOR).$(REVISION) >> doxygen.ini
	doxygen doxygen.ini

# create todo list
.PHONY : todo_list
todo_list : 
	grep -r TODO src || true

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


