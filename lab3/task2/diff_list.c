#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct diffs{
	long offset;
	unsigned char orig_value;
	unsigned char new_value;	
} diff;

typedef struct nodes node;
struct nodes{
	diff *diff_data;
	node *next; 
};


void list_print(node* diff_list, FILE* output){
	/*print the nodes in the list : pos , orig , new*/
	node* curr = diff_list;
	while(curr!=NULL){
		fprintf(output, "%ld %02X %02x\n", curr->diff_data->offset,
			       	curr->diff_data->orig_value,
			       	curr->diff_data->new_value);
		curr= curr->next;
	}

}

node* list_append(node* diff_list, diff* data){
	/*create a new node. make it the first and make it point to the list
	this makes sense so you wont need to find the last node and first one:
	first to know which to return , and last to append the new node*/
	node* latest = (node*) malloc(sizeof(node));
	/*memcpy(latest->diff_data, data, sizeof(diff));		       	*/
	latest->diff_data = data;
	latest->next =  diff_list;		       	
	return latest;

}

void list_free(node* diff_list){
	node* next;
	node* curr = diff_list;
       while(curr!=NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
}

