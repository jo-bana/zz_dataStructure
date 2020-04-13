#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_


#define OK		0
#define ERROR 	-1

typedef int ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode *next;	
}QNode;

typedef struct
{
	QNode* front;
	QNode* rear;	
}SqQueue;

int init_queue(SqQueue *Q);
int uinit_queue(SqQueue *Q);
int insert_queue(SqQueue *Q,ElemType e);
ElemType delete_queue(SqQueue *Q);
void printf_queue(SqQueue *Q);

#endif