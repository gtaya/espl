# All Targets
all: addresses

# Tool invocations
# Executable "addresses" depends on the file addresses.o

addresses: addresses.o
	gcc -m32 -g -Wall -o addresses addresses.o

addresses.o: addresses.c
	gcc -g -Wall -m32 -ansi -c -o addresses.o addresses.c

.PHONY: clean

clean:
	rm -f *.o addresses
