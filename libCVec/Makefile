FLAGS = -Wall -Wextra -std=c11 -Wpedantic

all: output/exec

output/exec: output/main.o output/CVec.o
	clang -o output/exec output/main.o output/CVec.o

output/main.o: main.c
	mkdir -p output && clang $(FLAGS) -I./src -c main.c -o output/main.o

output/CVec.o: src/CVec.c src/CVec.h
	clang $(FLAGS) -I./src -c src/CVec.c -o output/CVec.o

clean:
	rm -r output 