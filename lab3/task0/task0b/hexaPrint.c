#include <stdio.h>

void PrintHex(unsigned char* buffer, int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%02X", buffer[i]);
		if (i+1 < length)
			printf("%s", " ");
	}
	printf("%s", "\n");
}

int main(int argc, char** argv) {
	FILE* binfile = fopen(argv[1], "rb");
	unsigned char buffer[1024];
	size_t bytes_read;

	if (binfile != NULL) {

		while ((bytes_read = fread(buffer, 1, sizeof(buffer), binfile)) > 0) {
			PrintHex(&buffer[0], bytes_read);
		}
	}

	fclose(binfile);
	return 0;
}

