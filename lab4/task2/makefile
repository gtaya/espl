all: scmp1 scmp2

scmp1: scmp.o cmpstr1.o
	gcc -m32 -o scmp1 scmp.o cmpstr1.o

scmp2: scmp.o cmpstr2.o
	gcc -m32 -o scmp2 scmp.o cmpstr2.o

scmp.o: scmp.c
	gcc -m32 -c -o scmp.o scmp.c

cmpstr1.o: cmpstr.c
	gcc -m32 -c -o cmpstr1.o cmpstr.c

cmpstr2.o: cmpstr.s
	nasm -g -f elf -w+all -o cmpstr2.o cmpstr.s
	
.PHONY: clean

clean:
	rm -rf *.o scmp1 scmp2
