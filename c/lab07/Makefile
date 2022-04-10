targets = lab07.bin
CC = gcc
CFLAGS= -lm 
C_OPTS = -std=gnu11 -g -lm -Wall   
all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: lab07.bin

lab07.bin: src/lab07.c
	$(CC) $(C_OPTS) $< -o ./dist/$@


run: clean prep compile
	./dist/lab07.bin
format: #TODO

tidy: # TODO

