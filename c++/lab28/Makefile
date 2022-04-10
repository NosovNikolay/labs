CC = clang++
C_OPTS = -g -O0 -std=gnu++11 -Wall -Wextra -Wpedantic -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla
T_FORMAT = -f "[TIME]:\n-User\t%Us\n-System\t%Ss\n-Real\t%es"
OBJECTS = dist/Array.o

vpath %.hpp src
vpath %.cpp src
vpath %.cpp test
vpath %.o dist
vpath %.bin dist

.SILENT: compile prepare clean run test all test.bin main.bin darray.o discipline.o lecturer.o lldb.o tlldb.o val tval doxygen format check
.IGNORE: check

compile: prepare main.bin;
prepare:
	mkdir -p dist
clean:
	rm -rf dist

run: compile
	time $(T_FORMAT) ./dist/main.bin

all: compile
	time $(T_FORMAT) ./dist/main.bin
	time $(T_FORMAT) ./dist/test.bin

main.bin: main.cpp Array.o
	$(CC) $(C_OPTS) src/main.cpp $(OBJECTS) -Isrc -o dist/main.bin
Array.o: Array.cpp Array.hpp
	$(CC) $(C_OPTS) -c src/Array.cpp -Isrc -o dist/Array.o
