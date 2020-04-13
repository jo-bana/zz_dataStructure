#ifndef _D_LIST_STACK_H_
#define _D_LIST_STACK_H_

#define MAX_STACK_SIZE 		100
#define STACK_INCREMENT 	10
#define ERROR 			   -1
#define OK					0

typedef int ElemType;
typedef struct
{
	ElemType *bottom;
	ElemType *top;
	int stacksize;
}SqStack;

int init_stack(SqStack *S);
int push(SqStack *S,ElemType e);
ElemType pop(SqStack *S);
void list_stack(SqStack *S);

#endif
