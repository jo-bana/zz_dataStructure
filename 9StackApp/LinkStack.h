#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_

#define ERROR -1
#define OK 	   0

typedef char ElemType;
typedef struct stack_node
{
	ElemType data;
	struct stack_node *next;
}SqStack;

int init_stack(SqStack *S);
void uinit_stack(SqStack *S);
int push(SqStack *S,ElemType e);
ElemType pop(SqStack *S);
void list_stack(SqStack *S);
int stack_empty(SqStack *S);

#endif