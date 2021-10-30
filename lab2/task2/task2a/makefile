# All Targets
all: task2

# Tool invocations
# Executable "task2" depends on the files task2a.o

task2: task2a.o
	gcc -m32 -g -Wall -o task2 task2a.o

task2a.o: task2a.c
	gcc -g -Wall -m32 -ansi -c -o task2a.o task2a.c

.PHONY: clean

clean:
	rm -f *.o task2
