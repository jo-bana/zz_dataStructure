#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include <string.h>

#define TRUE   0
#define FALSE -1

int Match_Bracket(char *str)
{
	SqStack stack;
	int ret;
	char x;
	init_stack(&stack);
	if(ERROR==ret)
	{
		return FALSE;
	}
	int i,len=strlen(str);
	for(i=0;i<len;i++)
	{
		if('('==str[i] || '['==str[i])
		{
			push(&stack,str[i]);
		}
		else if(')'==str[i])
		{
			x=pop(&stack);
			if('('==x)
			{
				continue;
			}
			else
			{
				goto ERR;			
			}
		}
		else if(']'==str[i])
		{
			x=pop(&stack);
			if('['==x)
			{
				continue;
			}
			else
			{
				goto ERR;			
			}
		}
		else
		{
			continue;
		}
		
	}
	if(OK==stack_empty(&stack))
	{
		uinit_stack(&stack);
 		return TRUE;		
	}
ERR:
	uinit_stack(&stack);
	return FALSE;
}


int main(void)
{
	char tmp1[]={"[()][()()]"};
	char tmp2[]={"[()(])"};
	char tmp3[]={"[(()())]("};
	printf("*******%s*******\n",tmp1);
	int ret=Match_Bracket(tmp1);
	if(TRUE==ret)
	{
		printf("%s  bracket match!\n",tmp1);
	}
	else
	{
		printf("%s  bracket not match!\n",tmp1);
	}
	printf("*******%s*******\n",tmp2);
	ret=Match_Bracket(tmp2);
	if(TRUE==ret)
	{
		printf("%s  bracket match!\n",tmp2);
	}
	else
	{
		printf("%s  bracket not match!\n",tmp2);
	}
	printf("*******%s*******\n",tmp3);
	ret=Match_Bracket(tmp3);
	if(TRUE==ret)
	{
		printf("%s  bracket match!\n",tmp3);
	}
	else
	{
		printf("%s  bracket not match!\n",tmp3);
	}
}
