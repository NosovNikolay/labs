CC = clang
C_OPTS = -g -DDEBUG
OBJECTS = dist/*.o

VPATH = src:test:dist

.PHONY: test dox
.SILENT: prepare clean all run test gdb tgdb llvm tllvm dox check val tval format
.IGNORE: all

compile: prepare main.bin test.bin;
prepare:
	mkdir -p dist
clean:
	rm -rf dist

all: compile
	dist/main.bin
	dist/test.bin
run: prepare main.bin
	dist/main.bin
test: prepare test.bin
	dist/test.bin

main.bin: main.c list.o data.o
	$(CC) $(C_OPTS) $< $(OBJECTS) -I./src -o dist/main.bin
test.bin: test.c list.o data.o
	$(CC) $(C_OPTS) $< $(OBJECTS) -I./src -o dist/test.bin

list.o: list.c list.h
	$(CC) $(C_OPTS) -c $< -I./src -o dist/$@
data.o: data.c data.h
	$(CC) $(C_OPTS) -c $< -I./src -o dist/$@
	
gdb: dist/main.bin
	gdb dist/main.bin
tgdb: dist/test.bin
	gdb dist/test.bin

llvm: dist/main.bin
	llvm dist/main.bin
tllvm: dist/test.bin
	llvm dist/test.bin

dox: prepare
	rm -rf dist/html
	doxygen Doxyfile

check:
	cppcheck --enable=all --language=c --addon=cert.py -I./src src/
val: dist/main.bin
	valgrind --leak-check=full dist/main.bin
tval: dist/test.bin
	valgrind --leak-check=full dist/test.bin

