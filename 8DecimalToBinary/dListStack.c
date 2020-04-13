#include <stdio.h>
#include <stdlib.h>
#include "dListStack.h"


int init_stack(SqStack *S)
{
	if(!S)
	{
		return ERROR;
	}
	S->bottom=(ElemType *)malloc(MAX_STACK_SIZE*sizeof(ElemType));
	if(NULL==S->bottom)
	{
		printf("Stack init error!\n");
		return ERROR;
	}
	S->top=S->bottom;
	S->stacksize=MAX_STACK_SIZE;	
	return OK;
}

int push(SqStack *S,ElemType e)
{
	if(!S)
	{
		return ERROR;
	}
	if(S->top - S->bottom >= S->stacksize)
	{
		//追加分配内存空间给栈
		S->bottom=(ElemType*)realloc(S->bottom,(S->stacksize+STACK_INCREMENT)*sizeof(ElemType));
		if(NULL == S->bottom)
		{
			printf("add memory failure!\n");
			return ERROR;		
		}
		S->stacksize+=STACK_INCREMENT;
	}
	*(S->top)=e;
	(S->top)++;
	return OK;
}
ElemType pop(SqStack *S)
{
	if(!S)
	{
		return ERROR;
	}
	if(S->top == S->bottom)
	{
		return ERROR;
	}
	S->top--;
	return (*(S->top));
}

void list_stack(SqStack *S)
{
	ElemType *p;
	for(p=S->bottom;p<=S->top;p++)
	{
		printf("%d  ",*p);
	}
	printf("\n");
}



