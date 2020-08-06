#include <stdio.h>
#include "dListStack.h"

int InQueue(SqStack * S1,SqStack *S2,ElemType e)
{
	if(!S1||!S2)
	{
		return ERROR;
	}
	if(stack_empty(S1)==OK)
	{
		while(stack_empty(S2))
		{
			push(S1,pop(S2));
		}
	}
	return push(S1,e);
}
ElemType OutQueue(SqStack * S1,SqStack *S2)
{
		if(!S1||!S2)
	{
		return ERROR;
	}
	if(OK==stack_empty(S1) && OK==stack_empty(S2))
	{
		return ERROR;
	}
	if(stack_empty(S2)==OK)
	{
		while(stack_empty(S1))
		{
			push(S2,pop(S1));
		}
	}
	return pop(S2);
}


