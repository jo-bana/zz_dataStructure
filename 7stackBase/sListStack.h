#ifndef _S_LIST_STACK_H_
#define _S_LIST_STACK_H_


#define MAX_STACK_SIZE 100

#define ERROR -1
#define OK	   0

typedef int ElemType;

typedef struct
{
	ElemType stack_array[MAX_STACK_SIZE];
	int top;
	int bottom;
}SqStack;

int init_stack(SqStack* s);
int push(SqStack* s,ElemType e);
ElemType pop(SqStack *s);
void list_stack(SqStack *s);

#endif