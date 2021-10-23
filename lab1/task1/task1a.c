#include <stdio.h>
#include <string.h>

void getChars(unsigned char * a);

void char2ascii() {
	while (!feof(stdin)) {
		unsigned char c[256];
		getChars(&c[0]);
		int j = 0;

		while (c[j] != 0) {
			printf("%d", c[j]);
			if (c[j+1] != 0)
				printf("%s", " ");
			j++;
		}

		printf("%s", "\n");
		break;
	}
}
