# All Targets
all: char2ascii

# Tool invocations
#Executable "char2ascii" depends on the files task1a.o task1b.o task1c.o getChars.o toBinary.o and main.o
char2ascii: main.o task1a.o task1b.o task1c.o getChars.o toBinary.o
	gcc -m32 -g -Wall -o char2ascii main.o task1a.o task1b.o task1c.o getChars.o toBinary.o

main.o: main.c
	gcc -g -Wall -m32 -ansi -c -o main.o main.c

task1a.o: task1a.c
	gcc -g -Wall -m32 -ansi -c -o task1a.o task1a.c

task1b.o: task1b.c
	gcc -g -Wall -m32 -ansi -c -o task1b.o task1b.c

task1c.o: task1c.c
	gcc -g -Wall -m32 -ansi -c -o task1c.o task1c.c

getChars.o: getChars.c
	gcc -g -Wall -m32 -ansi -c -o getChars.o getChars.c

toBinary.o: toBinary.c
	gcc -g -Wall -m32 -ansi -c -o toBinary.o toBinary.c

.PHONY: clean

clean:
	rm -f *.o char2ascii
