#include <stdio.h>
#include <ctype.h>

void char2case(unsigned char * c) {
	while (!feof(stdin)) {
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
