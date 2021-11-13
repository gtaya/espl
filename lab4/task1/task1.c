#include <stdio.h>

extern int funcA(char* str);

int main(int argc, char** argv) {
	int len = funcA(argv[1]);
	printf("The length is %d\n", len);
	return 0;
}
