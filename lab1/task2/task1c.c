#include <stdio.h>
#include <ctype.h>

void char2case(unsigned char * c) {
	if (*c != 0) {
		if (isupper(*c)) {
			unsigned char temp = *c;
			*c = tolower(temp);
		}
		else {
			unsigned char temp = *c;
			*c = toupper(temp);
		}
	}
}
