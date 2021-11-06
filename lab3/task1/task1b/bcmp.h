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
