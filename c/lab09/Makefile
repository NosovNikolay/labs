targets = lab09.bin
CC = gcc
CFLAGS= -lm 
C_OPTS = -std=gnu11 -g -lm -Wall   
all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: lab09.bin

lab09.bin: src/lab09.c
	$(CC) $(C_OPTS) $< -o ./dist/$@


run: clean prep compile
	./dist/lab09.bin
format: #TODO

tidy: # TODO

