# All Targets
all: count-words

# Tool invocations
# Executable "count-words" depends on the file count-words.o

count-words: count-words.o
	gcc -m32 -g -Wall -o count-words count-words.o

count-words.o: count-words.c
	gcc -g -Wall -m32 -ansi -c -o count-words.o count-words.c

.PHONY: clean

clean:
	rm -f *.o count-words
