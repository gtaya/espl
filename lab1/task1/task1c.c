#include <stdio.h>
#include <ctype.h>

void getChars(unsigned char * c);

void char2case() {
	while (!feof(stdin)) {
		unsigned char c[256];
		getChars(&c[0]);
		int j = 0;

		while (c[j] != 0) {
			if (isupper(c[j]))
				printf("%c", tolower(c[j]));
			else
				printf("%c", toupper(c[j]));
			j++;
		}
		printf("%s", "\n");
		break;
	}
}
