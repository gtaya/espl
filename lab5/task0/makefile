all: prog

prog: task0.o open.o close.o
	gcc -m32 -g -Wall -o prog task0.o open.o close.o

task0.o: task0.c
	gcc -g -Wall -m32 -ansi -c -o task0.o task0.c

open.o: open.s
	nasm -g -f elf -w+all -o open.o open.s

close.o: close.s
	nasm -g -f elf -w+all -o close.o close.s

.PHONY: clean

clean:
	rm -f *.o prog
