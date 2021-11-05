# All Targets
all: task0

# Tool invocations
# Executable "task0" depends on the file bubblesort.o

task0: bubblesort.o
	gcc -m32 -g -Wall -o task0 bubblesort.o

bubblesort.o: bubblesort.c
	gcc -g -Wall -m32 -ansi -c -o bubblesort.o bubblesort.c

.PHONY: clean

clean:
	rm -f *.o task0
