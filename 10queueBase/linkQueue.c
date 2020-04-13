#include <stdio.h>
#include <stdlib.h>
#include "linkQueue.h"


int init_queue(SqQueue *Q)
{
	if(!Q)
	{
		return ERROR;
	}

	QNode *p;
	p=(QNode*)malloc(sizeof(QNode));
	if(!p)
	{
		printf("node malloc error!\n");
		return ERROR;
	}
	p->next=NULL;
	p->data=0;
	Q->front=Q->rear=p;
	return OK;
}

int uinit_queue(SqQueue *Q)
{
	if(!Q)
	{
		return ERROR;
	}
	//出队
	while(Q->front!=Q->rear)
	{
		delete_queue(Q);
	}
	//释放首节点
	free(Q->front);
	Q->front=Q->rear=NULL;
	return OK;
}
int insert_queue(SqQueue *Q,ElemType e)
{
	if(!Q)
	{
		return ERROR;
	}
	QNode *p;
	p=(QNode*)malloc(sizeof(QNode));
	if(!p)
	{
		printf("node malloc error!\n");
		return ERROR;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}
	
ElemType delete_queue(SqQueue *Q)
{
	if(!Q)
	{
		return ERROR;
	}
	QNode *p;
	ElemType tmp;
	p=Q->front->next;
	tmp=p->data;
	Q->front->next=p->next;
	if(Q->rear == p)//如果最后一个被删除要怎样返回
	{
		Q->rear=Q->front;
	}
	free(p);
	return tmp;
}
void printf_queue(SqQueue *Q)
{
	if(!Q)
	{
		return;
	}
	QNode *p;
	p=Q->front->next;
	while(NULL!=p)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");
}
