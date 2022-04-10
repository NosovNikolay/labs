CC = clang++
C_OPTS = -g -O0 -std=gnu++11 -Wall -Wextra -Wpedantic -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla
T_FORMAT = -f "[TIME]:\n-User\t%Us\n-System\t%Ss\n-Real\t%es"
OBJECTS = dist/barray.o dist/backpack.o dist/brand.o

vpath %.hpp src
vpath %.cpp src
vpath %.cpp test
vpath %.o dist
vpath %.bin dist

.SILENT: compile prepare clean run test all test.bin main.bin barray.o backpack.o brand.o lldb.o tlldb.o val tval doxygen format check
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

test.bin: test.cpp barray.o backpack.o brand.o
	$(CC) $(C_OPTS) test/test.cpp $(OBJECTS) -Isrc -o dist/test.bin

main.bin: main.cpp barray.o backpack.o brand.o
	$(CC) $(C_OPTS) src/main.cpp $(OBJECTS) -Isrc -o dist/main.bin
barray.o: barray.cpp barray.hpp
	$(CC) $(C_OPTS) -c src/barray.cpp -Isrc -o dist/barray.o
backpack.o: backpack.cpp backpack.hpp
	$(CC) $(C_OPTS) -c src/backpack.cpp -Isrc -o dist/backpack.o
brand.o: brand.cpp brand.hpp
	$(CC) $(C_OPTS) -c src/brand.cpp -Isrc -o dist/brand.o

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