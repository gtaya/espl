#include <stdio.h>

void toBinary(unsigned char c, char * byte, int byteLen) {
	int i;
	for (i = byteLen-1; i >= 0; i--) {
		byte[i] = c & 1;
		c >>= 1;
	}
}
