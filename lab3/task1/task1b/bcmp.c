#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bcmp.h"

typedef struct diffs diff;
typedef struct nodes node;

void list_print(node* diff_list, FILE* output);
node* list_append(node* diff_list, diff* data);
void list_free(node* diff_list);

void find_diffs(FILE* f1, FILE* f2, int length, node* diff_list) {
	int i = 0, len = sizeof(unsigned char);
	unsigned char f1_byte[len];
	unsigned char f2_byte[len];
	while (i < length) {
		fread(f1_byte, len, 1, f1);
		fread(f2_byte, len, 1, f2);
		if (f1_byte != f2_byte) {
			diff data  = {.offset = i, .orig_value = f1_byte, .new_value = f2_byte};
			diff* d1 = &data;
			list_append(diff_list, d1);
		}
		i++;
	}
}

int min(int a, int b) {
	return (a > b) ? b : a;
}

int main(int argc, char** argv){
	/*parse arguments*/
	FILE* output = stdout;
	int i,t=-1,k=-1;
	FILE *f1,*f2;
	node* diff_list;

	for(i=1; i<argc; i++){
		if(strcmp(argv[i], "-t")==0)
			t=1;
		else if(strcmp(argv[i], "-k")==0 && isdigit(argv[i]))
			k = atoi(argv[++i]);
		else if(strcmp(argv[i], "-o")==0)
			output = fopen(argv[++i],"a+");
		else if(i<argc){
			f1 = fopen(argv[i],"a+");
			f2 = fopen(argv[++i], "a+");			
			}
		}	


	/*get both sizes and keep the smaller one*/
	fseek(f1, 0, SEEK_END);
	fseek(f2, 0, SEEK_END);
	int size = min(ftell(f1), ftell(f2));
	
	/*iterate over both and find diffs for as many bytes as the shorter file*/
	find_diffs(f1, f2, size, diff_list);

	/*keep diffs in linkedlist using task1a*/

	/* print ll of diffs using task1a */
	list_print(diff_list, output);
	/*allow for flags: -o changes output , -k overrides bytes num, -t counts diff num */


	return 0;
}
