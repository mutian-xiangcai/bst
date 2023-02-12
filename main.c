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
	add(&tree,23);
	add(&tree,5);
	add(&tree,6);
	add(&tree,8);
	add(&tree,58);
	add(&tree,61);
	
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
