#include <stdio.h>
#include "list.h"

int main(void)
{
    int ret;
	List list;
	ElemType tmp;
	//����һ��˳��ṹ�ı�
	ret=Init_List(&list);
	if(ERROR == ret)
	{
    printf("Init failure!\n");
	return ;
	}
    //����в���Ԫ��
    while(1)
    {
		printf("please input a element:");
		scanf("%d",&tmp);
		if(tmp<0)
		{
	       //�˳�����
	       break;
		}
		ret = Insert_List(&list,0,tmp);
		if(ERROR == ret)
		{
		   printf("insert element error!\n");
		}
    }
   //��Ļ���������
   Print_List(&list);

   //�ӱ���ɾ��Ԫ��
   ret=Delete_List(&list,3);
   Print_List(&list);

   //ͨ��λ�ò�ֵ
  tmp=Search_List_by_Pos(&list,2);
   printf("in the list,position 2:%d\n",tmp);

   //ͨ��ֵ��λ��
   ret=Search_List_by_Value(&list,5);
   printf("in the list,5 at position:%d\n",ret);

   //��ñ����Ч����
   ret=Get_List_Length(&list);
   printf("the list length is:%d\n",ret);

   
   //���ٱ�
   UInit_List(&list);
   
}
