# All Targets
all: hexaPrint

# Tool invocations
# Executable "hexaPrint" depends on the file hexaPrint.o

hexaPrint: hexaPrint.o
	gcc -m32 -g -Wall -o hexaPrint hexaPrint.o

hexaPrint.o: hexaPrint.c
	gcc -g -Wall -m32 -ansi -c -o hexaPrint.o hexaPrint.c

.PHONY: clean

clean:
	rm -f *.o hexaPrint
