# All Targets
all: task2

# Tool invocations
# Executable "task2" depends on the file task2b.o

task2: task2b.o
	gcc -m32 -g -Wall -o task2 task2b.o

task2b.o: task2b.c
	gcc -g -Wall -m32 -ansi -c -o task2b.o task2b.c

.PHONY: clean

clean:
	rm -f *.o task2
