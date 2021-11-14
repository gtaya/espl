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

node* find_diffs(FILE* f1, FILE* f2, int length, diff * ptrs, int* count, int k) {
	int i = 0, len = sizeof(unsigned char);
	unsigned char f1_byte[len];
	unsigned char f2_byte[len];
	node *head = NULL;
	while (i < length&& k>0) {
		fread(f1_byte, len, 1, f1);
		fread(f2_byte, len, 1, f2);
		if (f1_byte[0] != f2_byte[0]) {	
			diff data = {.offset = i, .orig_value = *f1_byte, .new_value = *f2_byte};
			*ptrs = data;
			head =list_append(head, ptrs);
			ptrs++;
			*count+=1;
			k--;
		}
		i++;
	}
	return head;
}

int min(int a, int b) {
	return (a > b) ? b : a;
}

int main(int argc, char** argv){
	/*parse arguments*/
	FILE* output = stdout;
	int i,t = -1,k = -1, c =0;
	int* count = &c;
	FILE *f1, *f2;
	node* diff_list = NULL;
	diff arr[1000];

	for(i=1; i<argc; i++){
		if(strcmp(argv[i], "-t")==0)
			t=1;
		else if(strcmp(argv[i], "-k")==0)
			k = atoi(argv[++i]);
		else if(strcmp(argv[i], "-o")==0)
			output = fopen(argv[++i],"a+");
		else if(i<argc){
			f1 = fopen(argv[i],"rb");
			f2 = fopen(argv[++i], "rb");			
			}
		}	


	/*get both sizes and keep the smaller one*/
	fseek(f1, 0, SEEK_END);
	fseek(f2, 0, SEEK_END);
	int size = min(ftell(f1), ftell(f2));

	fseek(f1, 0, SEEK_SET);
	fseek(f2, 0, SEEK_SET);

	/*iterate over both and find diffs for as many bytes as the shorter file*/
	if(k==-1)
		diff_list = find_diffs(f1, f2, size, arr, count, size);
	else if(k!=-1)
		diff_list = find_diffs(f1, f2, size, arr, count, k);
	/* print all of diffs using task1a */
	if(t !=-1)
		fprintf(output, "%d\n", *count);
	/*allow for flags: -o changes output , -k overrides bytes num, -t counts diff num */
	else list_print(diff_list, output);
	

	list_free(diff_list);
	fclose(f1);
	fclose(f2);
	return 0;
}

