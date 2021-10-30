# All Targets
all: task2

# Tool invocations
# Executable "task2" depends on the file task2c.o

task2: task2c.o
	gcc -m32 -g -Wall -o task2 task2c.o

task2c.o: task2c.c
	gcc -g -Wall -m32 -ansi -c -o task2c.o task2c.c

.PHONY: clean

clean:
	rm -f *.o task2
