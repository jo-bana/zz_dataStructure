#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BTnode *create_tree()
{
	ElemType data;
	BTnode *p,*T,*s[MAX_SIZE];
	int i,j;
	while(1)
	{
		//输入该节点编号
		printf("please input node number:");//从一开始
		scanf("%d",&i);
		if(0==i)
		{
			break;
		}	
		//输入该节点数据
		printf("please input node data:");
		scanf("%d",&data);
		p=(BTnode*)malloc(sizeof(BTnode));
		if(!p)
		{
			return NULL;
		}		
		p->data=data;
		p->Lchild=p->Rchild=NULL;	
		//将节点与树联系起来
		s[i]=p;
		if(1==i)
		{
			T=p;			
		}
		else
		{
			j=i/2;
			if(0==i%2)
			{
				s[j]->Lchild=p;
			}
			else
			{
				s[j]->Rchild=p;
			}			
		}				
	}
	return T;
}
void PreorderTraverse(BTnode*T)
{
	if(T)
	{
		printf("%d ",T->data);
		PreorderTraverse(T->Lchild);
		PreorderTraverse(T->Rchild);		
	}
}
void InorderTraverse(BTnode*T)
{
	if(T)
	{
		InorderTraverse(T->Lchild);
		printf("%d ",T->data);
		InorderTraverse(T->Rchild);		
	}

}
void PosorderTraverse(BTnode*T)
{
	if(T)
	{
		
		PosorderTraverse(T->Lchild);
		PosorderTraverse(T->Rchild);
		printf("%d ",T->data);
	}

}
int destory_tree(BTnode*T)
{
	
	if(T)
	{
		destory_tree(T->Lchild);
		destory_tree(T->Rchild);
		free(T);		
	}
}

void print_leafNode(BTnode*T)//打印叶子结点
{
	if(T)
	{
	if(NULL==T->Lchild && NULL==T->Rchild)
	{
		printf("%d ",T->data);
	}
	print_leafNode(T->Lchild);
	print_leafNode(T->Rchild);	
	}
	
}

int tree_deep(BTnode*T)//树的深度
{
	if(T)
	{
		if(NULL==T->Lchild&&NULL==T->Rchild)
		{
			return 1;
		}
		int i,j;
		i=tree_deep(T->Lchild);
		j=tree_deep(T->Rchild);
		return (i+1)>(j+1)?(i+1):(j+1);
	}
}

void get_tree_n0_n2(BTnode*T,int *n0,int *n2)
{	
	if(T)
	{		
		if(NULL==T->Lchild && NULL==T->Rchild)
		{
			*n0=*n0+1;
		}
		else if(T->Lchild&&T->Rchild)
		{
			*n2=*n2+1;
		}
		
		get_tree_n0_n2(T->Lchild,n0,n2);
		get_tree_n0_n2(T->Rchild,n0,n2);		
	}
	
}


