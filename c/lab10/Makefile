targets = lab10.bin
CC = gcc
CFLAGS= -lm 
C_OPTS = -std=gnu11 -g -lm -Wall   
all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: lab10.bin

lab10.bin: src/lab10.c
	$(CC) $(C_OPTS) $< -o ./dist/$@


run: clean prep compile
	./dist/lab10.bin
format: #TODO

tidy: # TODO

