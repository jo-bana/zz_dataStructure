#include <stdio.h>
#include "link.h"

void main()
{
	LNode head1,head2;
		printf("***********head insert create***********\n");
		create_LinkList(&head1);
		printf_Link(&head1);
		printf("***********rear insert create***********\n");
		Rcreate_LinkList(&head2);
		printf_Link(&head2);
	
		printf("**************insert link****************\n");
		Insert_LNode(&head2,2,17);
		printf_Link(&head2);
		printf("**************delete link****************\n");
		Delete_LNode(&head2,3);
		printf_Link(&head2);
		printf("**************get element****************\n");
		ElemType tmp;
		tmp=Search_by_pos(&head2,3);
		printf("position 3 value:%d\n",tmp);
		printf("***************get node******************\n");
		LNode *m;
		m=Search_by_data(&head2,5);
		if(m)
		{
			printf("m->data= %2d \n",m->data);	
		}
		printf("*************get length******************\n");
		printf("link length:%d         link2 length:%d\n",Get_length(&head1),Get_length(&head2));

		destory_LinkList(&head1);
		destory_LinkList(&head2);
		

}
