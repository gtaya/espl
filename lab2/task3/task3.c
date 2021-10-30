#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void echo_printer(char c);
void ascii_printer(char c);
void binary_printer(char c);
void lower_to_upper_printer(char c);
void bitwise_or(char* s);
void string_printer(char* s, void (*func_ptr) (char));
void string_reader(char* s);

typedef struct {
	char* name;
	void (*func)(char);
} func_desc;

int main(int argc, char** argv) {
	func_desc echo = {.name = "Echo", .func = echo_printer};
	func_desc ascii = {.name = "ASCII", .func = ascii_printer};
	func_desc bin = {.name = "Binary", .func = binary_printer};
	func_desc l2u = {.name = "Lower to Upper", .func = lower_to_upper_printer};
	func_desc funcs[] = {echo, ascii, bin, l2u};
	char str[10], option[10];
	printf("Please enter a string (0 < size <= 10):\n");
	string_reader(str);
	printf("Select printer type:\n"
			"0 - %s\n"
			"1 - %s\n"
			"2 - %s\n"
			"3 - %s\n"
			"4 - Bitwise Or\n", funcs[0].name,
					funcs[1].name,
					funcs[2].name,
					funcs[3].name);
	while (option[0] != '\0' && !feof(stdin)) {
		printf("Option: ");
		string_reader(option);
		int num;
		if (!isdigit(option[0]))
			num = -1;
		else
			sscanf(option, "%d", &num);
		if (num < 0 || num > 4)
			printf("Invalid option. Select 0-4 or CTRL-D to exit.\n");
		else if (num == 4)
			bitwise_or(str);
		else
			string_printer(str, funcs[num].func);
	}
	printf("DONE.\n");
	return 0;
}
