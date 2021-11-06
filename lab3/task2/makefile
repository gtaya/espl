all: bcmp

bcmp: diff_list.o bcmp.o
	gcc -m32 -g -Wall -o bcmp diff_list.o bcmp.o

diff_list.o: diff_list.c
	gcc -g -Wall -m32 -ansi -c -o diff_list.o diff_list.c

bcmp.o: bcmp.c
	gcc -g -Wall -m32 -ansi -c -o bcmp.o bcmp.c

.PHONY: clean

clean:
	rm -f *.o bcmp
