#include <stdio.h>

void getFromFile(FILE* input, unsigned char* c) {
	int ch = 0, i = 0;
	while ((ch = fgetc(input)) != EOF) {
		c[i] = (char)ch;
		i++;
	}
	c[i] = 0;
}
