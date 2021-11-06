all: diff_list

diff_list: diff_list.o
	gcc -m32 -g -Wall -o diff_list diff_list.o

diff_list.o: diff_list.c
	gcc -g -Wall -m32 -ansi -c -o diff_list.o diff_list.c


.PHONY: clean

clean:
	rm -f *.o diff_list
