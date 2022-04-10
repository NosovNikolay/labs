CC = clang
C_OPTS = -g 

run: clean prep compile
	dist/main.bin
test: clean prep compile
	dist/test.bin
clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin test.bin

main.bin:
	$(CC) $(C_OPTS) src/main.c src/lib.c -I./src -o ./dist/$@
test.bin:
	$(CC) $(C_OPTS) test/test.c src/lib.c -I./src -o ./dist/$@
gdb: dist/main.bin
	gdb $<
check:
	cppcheck -I./src src/
val:
	valgrind dist/main.bin

	


