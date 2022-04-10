CC = clang++
C_OPTS = -g -O0 -std=gnu++11 -Wall -Wpedantic -Wformat-security -Wfloat-equal -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla
T_FORMAT = -f "[TIME]:\n-User\t%Us\n-System\t%Ss\n-Real\t%es"
OBJECTS = dist/Barray.o dist/Backpack.o dist/Brand.o dist/ClothBackpack.o dist/CBarray.o dist/LeatherBackpack.o dist/LBarray.o

vpath %.hpp src
vpath %.cpp src
vpath %.cpp test
vpath %.o dist
vpath %.bin dist

.SILENT: compile prepare clean run test all test.bin main.bin Barray.o Backpack.o Brand.o lldb.o tlldb.o val tval doxygen format check
.IGNORE: check

compile: prepare main.bin test.bin;
prepare:
	mkdir -p dist
clean:
	rm -rf dist

run: compile
	time $(T_FORMAT) ./dist/main.bin
test: compile
	time $(T_FORMAT) ./dist/test.bin
all: compile
	time $(T_FORMAT) ./dist/main.bin
	time $(T_FORMAT) ./dist/test.bin

test.bin: test.cpp Barray.o Backpack.o Brand.o
	$(CC) $(C_OPTS) test/test.cpp $(OBJECTS) -Isrc -o dist/test.bin

main.bin: main.cpp Barray.o Backpack.o Brand.o ClothBackpack.o CBarray.o LeatherBackpack.o LBarray.o
	$(CC) $(C_OPTS) src/main.cpp $(OBJECTS) -Isrc -o dist/main.bin
Barray.o: Barray.cpp Barray.hpp
	$(CC) $(C_OPTS) -c src/Barray.cpp -Isrc -o dist/Barray.o
Backpack.o: Backpack.cpp Backpack.hpp
	$(CC) $(C_OPTS) -c src/Backpack.cpp -Isrc -o dist/Backpack.o
Brand.o: Brand.cpp Brand.hpp
	$(CC) $(C_OPTS) -c src/Brand.cpp -Isrc -o dist/Brand.o
ClothBackpack.o: ClothBackpack.cpp ClothBackpack.hpp 
	$(CC) $(C_OPTS) -c src/ClothBackpack.cpp -Isrc -o dist/ClothBackpack.o
CBarray.o:
	$(CC) $(C_OPTS) -c src/CBarray.cpp -Isrc -o dist/CBarray.o
LeatherBackpack.o:
	$(CC) $(C_OPTS) -c src/LeatherBackpack.cpp -Isrc -o dist/LeatherBackpack.o
LBarray.o:
	$(CC) $(C_OPTS) -c src/LBarray.cpp -Isrc -o dist/LBarray.o

lldb: dist/main.bin
	lldb dist/main.bin
tlldb: dist/test.bin
	lldb dist/test.bin

val: dist/main.bin
	valgrind --leak-check=full dist/main.bin
tval: dist/test.bin
	valgrind --leak-check=full dist/test.bin

doxygen: prepare
	rm -rf dist/html
	doxygen Doxyfile
format:
	clang-format --verbose -i src/* test/*

check:
	clang-format --verbose --dry-run --Werror src/* test/*
	clang-tidy src/* test/*
	cppcheck --enable=all --language=c++ -I src --inconclusive --addon=cert --error-exitcode=1 --suppress=unmatchedSuppression --suppress=unreadVariable --verbose .