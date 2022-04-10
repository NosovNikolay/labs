targets = main.bin 
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra  -I./src src/lib.c

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: main.bin 

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@


run: clean prep compile
	./dist/main.bin
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO
