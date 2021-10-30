# All Targets
all: task3

# Tool invocations
# Executable "task2" depends on the files task2c.o task3.o

task3: task2c.o task3.o
	gcc -m32 -g -Wall -o task3 task2c.o task3.o

task2c.o: task2c.c
	gcc -g -Wall -m32 -ansi -c -o task2c.o task2c.c

task3.o: task3.c
	gcc -g -Wall -m32 -ansi -c -o task3.o task3.c

.PHONY: clean

clean:
	rm -f *.o task3
