targets = lab05.bin
CC = gcc
C_OPTS = -std=gnu11 -lm -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 	
all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: lab05.bin

lab05.bin: src/lab05.c
	$(CC) $(C_OPTS) $< -o ./dist/$@


run: clean prep compile
	./dist/lab05.bin
format: #TODO

tidy: # TODO

