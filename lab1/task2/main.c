#include <stdio.h>
#include <string.h>

void getChars(unsigned char * c);
void getFromFile(FILE * input, unsigned char * c);
void toBinary(unsigned char c, char * byte, int byteLen);
void char2case(unsigned char * c);

int main(int argc, char **argv) {
	int i, j = 0, len = 8;
	char opt = ' ', byte[len];
	unsigned char c[256];
	FILE * input = stdin;
	FILE * output = stdout;
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-b") == 0 && opt == ' ')	
			opt = 'b';
		else if (strcmp(argv[i], "-c") == 0 && opt == ' ')
			opt = 'c';
		else if (strcmp(argv[i], "-i") == 0)
			input = fopen(argv[++i], "r");
		else if (strcmp(argv[i], "-o") == 0)
			output = fopen(argv[++i], "a");
	}
	if (input != stdin)
		getFromFile(input, &c[0]);
	else
		getChars(&c[0]);

	while (c[j] != 0) {
		switch (opt) {
			case ' ':
				fprintf(output, "%d", c[j]);
				break;
			case 'b':
				toBinary(c[j], byte, len);
				for (i = 0; i < len; i++) {
					fprintf(output, "%d", byte[i]);
				}
				break;
			case 'c':
				char2case(&c[j]);
				fprintf(output, "%c", c[j]);
				break;
		}
		j++;
		if (c[j] != 0 && opt != 'c')
			fprintf(output, "%s", " ");
	}
	fprintf(output, "%s", "\n");
	if (output != stdout)
		fclose(output);
	return 0;
}

