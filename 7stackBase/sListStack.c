#include<stdio.h>
#include "sListStack.h"
#include <string.h>


int init_stack(SqStack *S)
{
  if(!S)
  	{
  	  return ERROR;
  	}
  memset(S,0,sizeof(SqStack));
  S->bottom=S->top=0;
  return OK;
}

int push(SqStack *S,ElemType e)//ѹջ
{
	if(!S)
  	{
  	  return ERROR;
  	}
	if(S->top >= MAX_STACK_SIZE-1)
		{
		  return ERROR;
		}
	(++S->top);
	S->stack_array[S->top]=e;
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
  
  ElemType e=S->stack_array[S->top];
  --(S->top);
  return e;
}

void list_stack(SqStack *S)
{
  if(!S)
  	{
  	  return ;
  	}
  int i;
  for(i=S->bottom+1;i<=S->top;i++)
  	{ 
  	  printf("%d",S->stack_array[i]);
  	}
  
}
