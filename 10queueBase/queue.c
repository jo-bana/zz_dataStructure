#include <stdio.h>
#include <string.h>
#include "queue.h"



int init_queue(SqQueue *Q)
{
	if(!Q)
	{
		return ERROR;
	}
	memset(Q,0,sizeof(SqQueue));
	Q->front=Q->rear=0;
	return OK;
}
int uinit_queue(SqQueue *Q)
{
	return init_queue(Q);	
}
int insert_queue(SqQueue *Q,ElemType e)
{
	if(!Q)
	{
		return ERROR;
	}
	//判断满队
	if((Q->rear+1)%MAX_QUEUE_SIZE == Q->front)
	{
		printf("queue is full!\n");
		return ERROR;	
	}
	Q->Queue_array[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAX_QUEUE_SIZE;
	return OK;
}
ElemType delete_queue(SqQueue *Q)
{
	if(!Q)
	{
		return ERROR;
	}
	//判断是否为空队列
	if(Q->front == Q->rear)
	{
		printf("queue is empty!\n");
		return ERROR;
	}
	ElemType tmp = Q->Queue_array[Q->front];
	Q->front=(Q->front+1)%MAX_QUEUE_SIZE;
		return tmp;
	
}
void printf_queue(SqQueue *Q)
{
	if(!Q || Q->front == Q->rear )
	{
		return;
	}
	int i;
	//for(i=Q->front;(i%MAX_QUEUE_SIZE)!=Q->rear;i++)
	for(i=Q->front;i!=Q->rear;i=(i+1)%MAX_QUEUE_SIZE)
	{
		printf("%d  ",Q->Queue_array[i]);
	}
	printf("\n");
}

//为什么是循环的队列
