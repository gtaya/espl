#include <stdio.h>

void getChars(unsigned char * c) {
	int j = 0, i = 0;

	while((j = fgetc(stdin)) != '\n')
		c[i++] = (char)j;
	c[i] = 0;
}
