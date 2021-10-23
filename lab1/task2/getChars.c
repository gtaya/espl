#include <stdio.h>

void getChars(unsigned char * c) {
	int j = 0, i = 0;

	while((j = fgetc(stdin)) != '\n')
		if (j != 32)
			c[i++] = (char)j;
	c[i] = 0;
}
