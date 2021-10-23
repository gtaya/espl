#include <stdio.h>
#include <string.h>

void char2ascii();
void char2binary();
void char2case();

int main(int argc, char **argv) {
	int i;
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-b") == 0) 
			char2binary();
		else if (strcmp(argv[i], "-c") == 0)
			char2case();
		else 
			char2ascii();
	}
	return 0;
}
