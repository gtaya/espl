#include <stdio.h>
#include <string.h>

void getChars(unsigned char * c);
void getFromFile(FILE * input, unsigned char * c);
void char2binary(unsigned char * c);
void char2case(unsigned char * c);

int main(int argc, char **argv) {
	int i, j = 0;
	char opt = ' ';
	unsigned char c[256];
	getChars(&c[0]);
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-b") == 0 && opt == ' ')	
			opt = 'b';
		else if (strcmp(argv[i], "-c") == 0 && opt == ' ')
			opt = 'c';
	}
	switch (opt) {
		case ' ':
			while (c[j] != 0) {
				printf("%d", c[j]);
				if (c[j+1] != 0)
					printf("%s", " ");
				j++;
			}
			printf("%s", "\n");
			break;
		case 'b':
			char2binary(&c[0]);
			break;
		case 'c':
			char2case(&c[0]);
			break;
	}
	return 0;
}
