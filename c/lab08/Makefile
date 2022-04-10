targets = lab08.bin
CC = gcc
CFLAGS= -lm 
C_OPTS = -std=gnu11 -g -lm -Wall   
all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: lab08.bin

lab08.bin: src/lab08.c
	$(CC) $(C_OPTS) $< -o ./dist/$@


run: clean prep compile
	./dist/lab08.bin
format: #TODO

tidy: # TODO

