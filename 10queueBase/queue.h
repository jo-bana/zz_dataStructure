#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_QUEUE_SIZE 5
#define OK		0
#define ERROR	-1


typedef int ElemType;
typedef struct
{
	ElemType Queue_array[MAX_QUEUE_SIZE];
	int front;
	int rear;
}SqQueue;

int init_queue(SqQueue *Q);
int uinit_queue(SqQueue *Q);
int insert_queue(SqQueue *Q,ElemType e);
ElemType delete_queue(SqQueue *Q);
void printf_queue(SqQueue *Q);

#endif