#include <stdio.h>
//#include "sListStack.h"
//#include "dListStack.h"
#include "LinkStack.h"



#define MAX_G 100
#define MODE2 2
#define MODE8 8
#define MODE16 16



void personalMode(int x)
{
	int data[MAX_G]={0};
	int mode = MODE16;
	int bit=0;
	int i;
	do
	{
		data[bit++]=x%mode;
		x/=mode;
	}while(x>0);
	printf("personal mode result:");
	for(i=bit-1;i>=0;i--)
	{
		printf("%x",data[i]);
	}
	printf("\n");
}

void stackMode(int x)/*void是无返回类型*/
{
	SqStack data;
	int ret = init_stack(&data);
	if(ret<0)
	{
		printf("stack init error!\n");
		return ;
	}
	int mode = MODE16;
	int bit=0;
	do
	{
		push(&data,x%mode);
		x/=mode;
	}while(x>0);
	printf("stack personal mode result:");
	while(1)
	{
		bit=pop(&data);
		if(bit<0)
		{
			break;
		}
		printf("%x",bit);
	}
	
	printf("\n");

}


int main(void)
{
	int a;
	printf("please input a decimal positive number:");
	scanf("%d",&a);
	personalMode(a);

	printf("****************************************\n");
	stackMode(a);
	
}
