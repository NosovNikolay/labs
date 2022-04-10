CC = clang
C_OPTS = -g -Wall -Wextra -DDEBUG
OBJECTS = dist/*.o

VPATH = src:test:dist

.PHONY: compile prepare clean test tgdb dox check tval format
.SILENT: compile prepare clean test libddllist.a libddllist.so test.bin list.o data.o tgdb dox check tval format
.IGNORE: test.bin test

compile: prepare libddllist.a test.bin;
prepare:
	mkdir -p dist
clean:
	rm -rf dist

test: prepare test.bin
	time dist/test.bin

libddllist.a: list.o data.o
	ar r dist/libddllist.a $(OBJECTS)
libddllist.so: list.o data.o
	$(CC) $(C_OPTS) -shared $(OBJECTS) -o dist/libddllist.so
test.bin: test.c libddllist.a list.h data.h
	$(CC) $(C_OPTS) test/test.c -I./src -L./dist -lddllist -o dist/test.bin

list.o: list.c list.h
	$(CC) $(C_OPTS) -fPIC -c $< -I./src -o dist/list.o
data.o: data.c data.h
	$(CC) $(C_OPTS) -fPIC -c $< -I./src -o dist/data.o

tgdb: dist/test.bin
	gdb dist/test.bin

dox: prepare
	rm -rf dist/html
	doxygen Doxyfile

check:
	cppcheck --enable=all --language=c --addon=cert.py -I./src src/
tval: dist/test.bin
	valgrind --leak-check=full dist/test.bin
