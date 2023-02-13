#include <stdio.h>
#include <stdlib.h>
#include <test.h>
#include <stdarg.h>

void hello();

int main(int argc, char *argv[]) {
	//������ 
	bst tree;
	//��ʼ���� 
	init(&tree);
	//��ӡ���Ĵ�С 
	printf("%d\n",tree.size);
	
	//���Ԫ�� 
	append(&tree,23);
	append(&tree,5);
	append(&tree,6);
	append(&tree,8);
	append(&tree,58);
	append(&tree,61);
	
	//��ӡ���Ĵ�С 
	printf("%d\n",tree.size);
	
	//����Ԫ�� 
	puts("----------------------\n");
	beforeGet(tree.root);
	puts("----------------------\n");
	targetGet(tree.root);
	puts("----------------------\n");
	afterGet(tree.root);
	puts("----------------------\n");
	printf("%d\n",tree.root->flag);
	atexit(hello);
	return 0;
}

void hello(){
	puts("hello\n");
}
