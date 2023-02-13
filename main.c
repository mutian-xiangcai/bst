#include <stdio.h>
#include <stdlib.h>
#include <test.h>
#include <stdarg.h>

void hello();

int main(int argc, char *argv[]) {
	//声明树 
	bst tree;
	//初始化树 
	init(&tree);
	//打印树的大小 
	printf("%d\n",tree.size);
	
	//添加元素 
	append(&tree,23);
	append(&tree,5);
	append(&tree,6);
	append(&tree,8);
	append(&tree,58);
	append(&tree,61);
	
	//打印树的大小 
	printf("%d\n",tree.size);
	
	//遍历元素 
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
