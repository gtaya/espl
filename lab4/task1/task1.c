#include <stdio.h>

extern int funcA(char* str);

int main(int argc, char** argv) {
	int len = funcA(argv[1]);
	printf("%d is the str len\n", len);
	return 0;
}
