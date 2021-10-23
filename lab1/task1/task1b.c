#include <stdio.h>

void getChars(unsigned char * a);

void toBinary(unsigned char c, char* byte, int byteLen);

void char2binary() {
	while (!feof(stdin)) {
		unsigned char c[256];
		getChars(&c[0]);
		int j = 0, len = 8;

		while (c[j] != 0) {
			char byte[len];
			toBinary(c[j], byte, len);			
			int i;
			for (i = 0; i < len; i++) {
				printf("%d", byte[i]);
			}
			if (c[j+1] != 0)
				printf("%s", " ");
			j++;
		}
		printf("%s", "\n");
		break;
	}
}
