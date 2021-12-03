#include <stdio.h>

int open(const char* filename);
int close(int fd);

int main(int argc, char** argv) {
	int fd = open(argv[1]);
	printf("The file descriptor is %d\n", fd);
	int close_op = close(fd);
	char* close_msg = (close_op == -1) ? "CLOSING FAILED" : "CLOSING DONE";
	printf("%s\n", close_msg);
	return 0;
}
