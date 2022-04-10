targets = lab06.bin
CC = gcc
CFLAGS= -lm 
C_OPTS = -std=gnu11 -g -lm -Wall   
all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: lab06.bin

lab06.bin: src/lab06.c
	$(CC) $(C_OPTS) $< -o ./dist/$@


run: clean prep compile
	./dist/lab06.bin
format: #TODO

tidy: # TODO

