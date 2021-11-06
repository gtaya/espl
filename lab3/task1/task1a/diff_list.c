#include <stdio.h>
#include <stdlib.h>


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


int main(){
	/*
	FILE* output;
	output = stdout;
	diff d1,d2,d3;
	diff *dp1 = &d1;
	diff *dp2 = &d2;
	diff *dp3 = &d3;
	*dp1  =(diff){1, 0x40, 0x20 };
	*dp2 =(diff){3, 0x50, 0x55 };
	d3 =(diff){17, 0xFF, 0x0A };
	node* out=NULL;
	out =list_append(out, dp1);
	out =list_append(out, dp2);
	out =list_append(out, dp3);
	list_print(out,output);	
	list_free(out);
*/
	return 0;
	

}
