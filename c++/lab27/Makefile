CC = clang++
C_OPTS = -g -O0 -std=gnu++11 -Wall -Wpedantic -Wformat-security -Wfloat-equal -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla
T_FORMAT = -f "[TIME]:\n-User\t%Us\n-System\t%Ss\n-Real\t%es"
OBJECTS = dist/BArray.o dist/Backpack.o dist/Brand.o dist/ClothBackpack.o dist/LeatherBackpack.o

vpath %.hpp src
vpath %.cpp src
vpath %.cpp test
vpath %.o dist
vpath %.bin dist

.SILENT: compile prepare clean run test all test.bin main.bin BArray.o Backpack.o Brand.o lldb.o tlldb.o val tval doxygen format check
.IGNORE: check

compile: prepare main.bin ;
prepare:
	mkdir -p dist
clean:
	rm -rf dist

run: compile
	time $(T_FORMAT) ./dist/main.bin
# test: compile
# 	time $(T_FORMAT) ./dist/test.bin
all: compile
	time $(T_FORMAT) ./dist/main.bin
	time $(T_FORMAT) ./dist/test.bin

# test.bin: test.cpp BArray.o Backpack.o Brand.o
# 	$(CC) $(C_OPTS) test/test.cpp $(OBJECTS) -Isrc -o dist/test.bin

main.bin: main.cpp BArray.o Backpack.o Brand.o ClothBackpack.o LeatherBackpack.o 
	$(CC) $(C_OPTS) src/main.cpp $(OBJECTS) -Isrc -o dist/main.bin
BArray.o: BArray.cpp BArray.hpp
	$(CC) $(C_OPTS) -c src/BArray.cpp -Isrc -o dist/BArray.o
Backpack.o: Backpack.cpp Backpack.hpp
	$(CC) $(C_OPTS) -c src/Backpack.cpp -Isrc -o dist/Backpack.o
Brand.o: Brand.cpp Brand.hpp
	$(CC) $(C_OPTS) -c src/Brand.cpp -Isrc -o dist/Brand.o
ClothBackpack.o: ClothBackpack.cpp ClothBackpack.hpp 
	$(CC) $(C_OPTS) -c src/ClothBackpack.cpp -Isrc -o dist/ClothBackpack.o
LeatherBackpack.o:
	$(CC) $(C_OPTS) -c src/LeatherBackpack.cpp -Isrc -o dist/LeatherBackpack.o

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