#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int init_stack(SqStack *S)
{
	if(!S)
	{
		return ERROR;
	}
	S->next = NULL;
	return OK;
}


int push(SqStack *S,ElemType e)
{
	if(!S)
	{
		return ERROR;		
	}
	SqStack *p;
	p=(SqStack*)malloc(sizeof(SqStack));
	if(!p)
	{
		printf("malloc stack failure!\n");
		return ERROR;
	}
	p->data=e;
	p->next=S->next;
	S->next=p;
}
ElemType pop(SqStack *S)
{
	if(!S)
	{
		return ERROR;		
	}
	if(NULL == S->next)
	{
		return ERROR;
	}
	SqStack *p;
	ElemType tmp;
	p=S->next;
	tmp=p->data;
	S->next=p->next;
	free(p);
	return tmp;
}
void list_stack(SqStack *S)
{
	if(!S)
	{
		return ;		
	}
	SqStack *p;
	p=S->next;
	while(p)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
	printf("\n");

}
//whether stack empty:
//empty: return ok
//not empty:return error
int stack_empty(SqStack *S)
{
	if(NULL != S->next)
	{
		return ERROR;		
	}
	else
	{
		return OK;
	}
	
}
