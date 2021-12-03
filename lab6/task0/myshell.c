#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include "LineParser.h"
#include <string.h>

int execute(cmdLine *pCmdLine) {
	int code;
	if ((code = execv(pCmdLine->arguments[0], pCmdLine->arguments))<0) {
		perror("execv error");
	}
	return code;
}	

int main(int argc, char** argv) {

	char cwd[PATH_MAX];
	char user_input[2048];

	while (1) {
		/* get current working directory */
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			printf("%s\n", cwd);
		} else {
			perror("Path length exceeds PATH_MAX");
			return 1;
		}

		/* get user command */
		fgets(user_input, sizeof(user_input), stdin);

		/* parse command */
		cmdLine* command = parseCmdLines(user_input);

		/* check if should quit */
		if (strcmp(command->arguments[0], "quit") == 0) {
			/* free lines */
			freeCmdLines(command);
			break;
		}
		execute(command);
		freeCmdLines(command);
	}
	return 0;
}
