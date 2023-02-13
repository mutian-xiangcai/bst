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


typedef struct fg{
	struct node* parent;
	char wh;
}parent;

void init(bst* tree);

void append(bst* tree,int data);

static void search(node* root,node* element);

void beforeGet(node* root);

void targetGet(node* root);

void afterGet(node* root);

void balance(parent father,node* root);

void balanceChildLeft(parent father,node* root);

void balanceChildRight(parent father,node* root);
