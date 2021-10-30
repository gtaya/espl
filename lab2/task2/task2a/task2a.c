#include <stdio.h>
#include <ctype.h>

void echo_printer(char c) {
	printf("%c", c);
	printf("%s", "\n");
}

void ascii_printer(char c) {
	printf("%d", c);
	printf("%s", "\n");
}

void binary_printer(char c) {
	int i, len = 8;
	char byte[len];
	for (i = len-1; i >= 0; i--) {
		byte[i] = c & 1;
		c >>=1;
	}
	for (i = 0; i < len; i++) {
		printf("%d", byte[i]);
	}
	printf("%s", "\n");
}
void lower_to_upper_printer(char c) {
	printf("%c", toupper(c));
	printf("%s", "\n");
}

void string_printer(char* str, void (*func_ptr) (char)) {
	/*TODO: Complete during task2b */
}

void string_reader(char* s) {
	/*TODO: Complete during task2c */
}

void bitwise_and(char* s) {
	/*TODO: Complete during task2c */
}

int main(int argc, char** argv) {
	return 0;
}
