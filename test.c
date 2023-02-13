#include <test.h>
#include <stdlib.h>
#include <stdio.h>

void init(bst* tree){
	tree->size = 0;
	tree->root = NULL;
}

void append(bst* tree,int data){
	//创建节点 
	node* element = (node*)malloc(sizeof(node));
	
	node* root = tree->root;
	//初始化element 
	element->data = data;
	element->lc = NULL;
	element->rc = NULL;
	element->lh = 0;
	element->rh= 0;
	element->flag = 0;
	
	//加入节点 
	if(root == NULL){
		tree->root = element;
		tree->size += 1;
	}else{
		search(root,element);
		tree->size += 1;
		if(root->lc == NULL){
			root->lh = 0;
		}else{
			root->lh = root->lc->lh > root->lc->rh ? root->lc->lh +1:root->lc->rh +1;
		}
		
		if(root->rc == NULL){
			root->rh = 0;
		}else{
			root->rh = root->rc->lh > root->rc->rh ? root->rc->lh +1:root->rc->rh +1;
		}
		
		root->flag = root->lh - root->rh;
	}
	
	root = tree->root;
}

static void search(node* root,node* element){
	
	int r_data = root->data;
	
	int e_data = element->data;
	
	if(e_data > r_data){
		if(root->rc == NULL){
			root->rc = element;
		}else{
			search(root->rc,element);
		}
		
	}else if(e_data == r_data){
		root->data = element->data;
	}else{
		if(root->lc == NULL){
			root->lc = element;
		}else{
			search(root->lc,element);
		}	
	}
	
	if(root->lc == NULL){
		root->lh = 0;
	}else{
		root->lh = root->lc->lh > root->lc->rh ? root->lc->lh +1:root->lc->rh +1;
	}
	
	if(root->rc == NULL){
		root->rh = 0;
	}else{
		root->rh = root->rc->lh > root->rc->rh ? root->rc->lh +1:root->rc->rh +1;
	}
	
	root->flag = root->lh - root->rh;
}

//-----------------------------------------

void balance(parent father,node* root){
	if(abs(root->flag) >= 2){
		if(root->lh > root->rh){
			if(root->rc == NULL){
				switch(father.wh){
					case 'l': {
						father.parent->lc = root->lc;
						root->lc = root->lc->rc;
						father.parent->lc->rc = root;
					};break;
					case 'r':{
						father.parent->rc = root->lc;
						root->lc = root->lc->rc;
						father.parent->rc->rc = root;
					};break;
				}
			}else{
				parent kk;
				kk.parent = root;
				kk.wh = 'l';
				if(root->lc->flag > 0){
					switch(father.wh){
						case 'l': {
							father.parent->lc = root->lc;
							root->lc = root->lc->rc;
							father.parent->lc->rc = root;
						};break;
						case 'r':{
							father.parent->rc = root->lc;
							root->lc = root->lc->rc;
							father.parent->rc->rc = root;
						};break;
					}
				}else{
					balanceChildLeft(kk,root->lc);
				}
			}
		}else{
			if(root->lc == NULL){
				switch(father.wh){
					case 'l': {
						father.parent->lc = root->rc;
						root->rc = root->rc->lc;
						father.parent->lc->lc = root;
					};break;
					case 'r':{
						father.parent->rc = root->rc;
						root->rc = root->rc->lc;
						father.parent->rc->lc = root;
					};break;
				}
			}else{
				parent kk;
				kk.parent = root;
				kk.wh = 'r';
				if(root->rc->flag < 0){
					switch(father.wh){
						case 'l': {
							father.parent->lc = root->rc;
							root->rc = root->rc->lc;
							father.parent->lc->lc = root;
						};break;
						case 'r':{
							father.parent->rc = root->rc;
							root->rc = root->rc->lc;
							father.parent->rc->lc = root;
						};break;
					}
				}else{
					balanceChildRight(kk,root->lc);
				}
			}
		}
	}
}

void balanceChildLeft(parent father,node* root){
	switch(father.wh){
		case 'l': {
			father.parent->lc = root->rc;
			root->rc = root->lc->rc;
			father.parent->lc->rc = root;
		};break;
		case 'r':{
			father.parent->rc = root->lc;
			root->lc = root->lc->rc;
			father.parent->rc->rc = root;
		};break;
	}
}

void balanceChildRight(parent father,node* root){
	switch(father.wh){
		case 'l': {
			father.parent->lc = root->lc;
			root->lc = root->lc->rc;
			father.parent->lc->rc = root;
		};break;
		case 'r':{
			father.parent->rc = root->lc;
			root->lc = root->lc->rc;
			father.parent->rc->rc = root;
		};break;
	}
}

//---------------------------

void beforeGet(node* root){
	if(root->lc == NULL){
	}else{
		beforeGet(root->lc);
	}
		
	printf("%d\n",root->data);
		
	if(root->rc == NULL){
	}else{
		beforeGet(root->rc);
	}
}

void targetGet(node* root){
	printf("%d\n",root->data);
	
	if(root->lc == NULL){
	}else{
		beforeGet(root->lc);
	}
		
	if(root->rc == NULL){
	}else{
		beforeGet(root->rc);
	}	
}

void afterGet(node* root){
	if(root->rc == NULL){
	}else{
		beforeGet(root->rc);
	}
		
	printf("%d\n",root->data);
		
	if(root->lc == NULL){
	}else{
		beforeGet(root->lc);
	}
}
