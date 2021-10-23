# All Targets
all: numbers

# Tool invocations
# Executable "numbers" depends on the file numbers.o

numbers: main.o numbers.o add.o
	@echo 'Building target: numbers'
	gcc -m32 -g -Wall -o numbers main.o numbers.o add.o
	@echo 'Finished'
	@echo ''

main.o: main.c
	gcc -g -Wall -m32 -ansi -c -o main.o main.c

numbers.o: numbers.c
	gcc -g -Wall -m32 -ansi -c -o numbers.o numbers.c

add.o: add.s
	nasm -g -f elf -w+all -o add.o add.s

.PHONY: clean

clean:
	rm -f *.o numbers
