typedef struct node{
	int lh;
	int rh;
	char flag;
	int data;
	struct node* lc;
	struct node* rc;
} node;

typedef struct bst{
	struct node* root;
	int size;
} bst; 

void init(bst* tree);

void add(bst* tree,int data);

static void search(node* root,node* element);

void beforeGet(node* root);

void targetGet(node* root);

void afterGet(node* root);

void balance(node* root);
