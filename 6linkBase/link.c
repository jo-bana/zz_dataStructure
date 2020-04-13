#include <stdio.h>
#include <stdlib.h>
#include "link.h"


//ͷ�ڵ���뷨�����б�
int create_LinkList(LNode* L)  /*���򴴽��б�*/
{
	if(!L)
 	{
		return ERROR;
	}
	L->next=NULL;
	ElemType data;
	LNode *p;
	while(1)
	{
		scanf("%d",&data);
		if(data<0)
		{
			break;
		}
		p=(LNode*)malloc(sizeof(LNode));
		//�Ժ󵽹�˾Ҫ�ж�pֵ����Ч��
		p->data = data;
		p->next = L->next;
		L->next = p;
	}
}

//β�ڵ���뷨��������
int Rcreate_LinkList(LNode* L)	/*���򴴽��б�*/
{
	if(!L)
		{
			return ERROR;
		}
		L->next=NULL;
		ElemType data;
		LNode *p,*q;
		q=L;
		while(1)
		{
			scanf("%d",&data);
			if(data<0)
			{
				break;
		
			}
		p=(LNode*)malloc(sizeof(LNode));
		p->data=data;
		p->next=q->next;
		q->next=p;
		q=p;
		}
}


int Insert_LNode(LNode* L,int pos,ElemType e)
{
	if(!L || pos<0 || pos>=Get_length(L))
	{
		return ERROR;
	}
	//��λ
	LNode *p,*q;
	int i;
	p=L->next;
	for(i=1;i<pos;i++)
	{
		p=p->next;
	}
	//����
	q=(LNode*)malloc(sizeof(LNode));
	q->data=e;
	q->next=p->next;
	p->next=q;
	return OK;
		
}


int Delete_LNode(LNode* L,int pos)
{
	if(!L || pos<0 || pos>=Get_length(L))
	{
		return ERROR;
	}
	LNode *p,*q;
	int i;
	//��λ
	p=L->next;
	q=L;
	for(i=1;i<pos;i++)
	{
		q=p;
		p=p->next;
		//q=q->next;
	}
	//ɾ��
	q->next=p->next;
	free(p);
	return OK;
}


ElemType Search_by_pos(LNode* L,int pos)
{
if(!L)
	{
		return ERROR;
	}
	LNode *p;
	int i;
	p=L->next;
	for(i=1;i<pos;i++)
	{
		p=p->next;
	}                 //��λ
	return p->data;  //����ֵ
}

LNode*  Search_by_data(LNode* L,ElemType e)
{
	if(!L)
	{
		return NULL;
	}
	LNode *p;
	p=L->next;
	while(NULL!=p && p->data!=e)
	{
		p=p->next;
	}
	return p;
}

int Get_length(LNode* L)
{
	if(!L)
	{
	return ERROR;
	}
	int i=0;
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}


int destory_LinkList(LNode* L)
{
	if(!L)
	{
		return ERROR;
	}
	LNode *p,*q;
	p=L->next;
	q=L;
	while(p)
	{
	q=p;
	p=p->next;
	free(q);
	}
	return OK;	
}

int printf_Link(LNode* L)
{
	if(!L)
	{
		return ERROR;
	}
	LNode *p;
	p=L->next;
	while(p)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

