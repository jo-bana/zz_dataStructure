#include <stdio.h>
#include <string.h>
//#include "queue.h"
#include "linkQueue.h"

int main(void)
{
	SqQueue queue;
	int ret,data,i;
	ret=init_queue(&queue);
	if(ret)
	{
		printf("queue init error!\n");
		return;
	}
	for(i=0;i<2;i++)
 {
		printf("****************insert queue***************\n");
		while(1)
	{
			scanf("%d",&data);			
		
		if(data<0)
		{
			break;
		}
		insert_queue(&queue,data);
		printf_queue(&queue);
	}
	
	printf("****************delete queue***************\n");
		while(1)
	{
		scanf("%d",&data);					
		if(data<0)
		{
			break;
		}
		ret=delete_queue(&queue);
		printf_queue(&queue);
	}
  }
	uinit_queue(&queue);
}
