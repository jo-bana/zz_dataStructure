#ifndef _TREE_H_
#define _TREE_H_

#define MAX_SIZE 256
#define ERROR -1
#define OK	   0

typedef int ElemType;

typedef struct BTnode
{
	struct BTnode *Lchild, *Rchild;
	ElemType data; 
}BTnode;

BTnode *create_tree();
void PreorderTraverse(BTnode*T);
void InorderTraverse(BTnode*T);
void PosorderTraverse(BTnode*T);
int destory_tree(BTnode*T);
void print_leafNode(BTnode*T);
int tree_deep(BTnode*T);
void get_tree_n0_n2(BTnode*T,int *n0,int *n2);

#endif