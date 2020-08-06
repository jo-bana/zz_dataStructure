#include <stdio.h>
#include "tree.h"

void main()
{
	int x=0,y=0;
	BTnode *tree;
	tree=create_tree();
	printf("*****************pre*******************\n");
	PreorderTraverse(tree);
	printf("\n");
	printf("*****************mid*******************\n");
	InorderTraverse(tree);
	printf("\n");
	printf("*****************last*******************\n");
	PosorderTraverse(tree);
	printf("\n");
	printf("*****************leaf*******************\n");
	print_leafNode(tree);
	printf("\n");
	printf("*****************deep*******************\n");
	printf("%d",tree_deep(tree));
	printf("\n");
	printf("***************n0*****n2******************\n");
	get_tree_n0_n2(tree,&x,&y);
	printf("%d %d",x,y);
	printf("\n");
	
	destory_tree(tree);
}
