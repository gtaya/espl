#include <stdio.h>
#include <ctype.h>
#include <string.h>

void echo_printer(char c) {
	printf("%c", c);
}

void ascii_printer(char c) {
	printf("%d", c);
}

void binary_converter(char c, char * byte, int len) {
	int i;
	for (i = len-1; i >= 0; i--) {
		byte[i] = c & 1;
		c >>=1;
	}
}

void binary_printer(char c) {
	int i, len = 8;
	char byte[len];
	binary_converter(c, byte, len);
	for (i = 0; i < len; i++) {
		printf("%d", byte[i]);
	}
}

void lower_to_upper_printer(char c) {
	printf("%c", toupper(c));
}

void string_printer(char* str, void (*func_ptr) (char)) {
	int i, len = strlen(str);
	for(i = 0; i < len; i++) {
		func_ptr(str[i]);
		if (i+1 != len) {
			printf("%s", " ");
		}
	}
	printf("%s", "\n");
}

void string_reader(char* s) {
	char* temp;
	if ((temp = fgets(s, sizeof(s), stdin)) != NULL) {
		s = temp;
	}
}

void bitwise_or(char* s) {
	int i;
	char res = s[0];
	for (i = 1; i < strlen(s); i++) {
		res = res | s[i];
	}
	binary_printer(res);
	printf("%s", "\n");
}
