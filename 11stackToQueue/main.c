#include <stdio.h>
#include "dListStack.h"

extern int InQueue(SqStack * S1,SqStack *S2,ElemType e);
extern ElemType OutQueue(SqStack * S1,SqStack *S2);


void main()
{
	ElemType data;
	SqStack stack1,stack2;
	init_stack(&stack1);
	init_stack(&stack2);

	printf("***********insert queue************\n");
	while(1)
	{
		scanf("%d",&data);
		if(data<0)
		{
			break;
		}
		InQueue(&stack1,&stack2,data);
	}
	printf("***********out queue************\n");
	while(1)
	{
		scanf("%d",&data);
		if(data<0)
		{
			break;
		}
		data = OutQueue(&stack1,&stack2);
		printf("out queue :%d\n",data);
	}
	uinit_stack(&stack1);
	uinit_stack(&stack2);
}
