#include <stdio.h>
#include "list.h"

int main(void)
{
    int ret;
	List list;
	ElemType tmp;
	//创建一个顺序结构的表
	ret=Init_List(&list);
	if(ERROR == ret)
	{
    printf("Init failure!\n");
	return ;
	}
    //向表中插入元素
    while(1)
    {
		printf("please input a element:");
		scanf("%d",&tmp);
		if(tmp<0)
		{
	       //退出插入
	       break;
		}
		ret = Insert_List(&list,0,tmp);
		if(ERROR == ret)
		{
		   printf("insert element error!\n");
		}
    }
   //屏幕输出表内容
   Print_List(&list);

   //从表中删除元素
   ret=Delete_List(&list,3);
   Print_List(&list);

   //通过位置查值
  tmp=Search_List_by_Pos(&list,2);
   printf("in the list,position 2:%d\n",tmp);

   //通过值查位置
   ret=Search_List_by_Value(&list,5);
   printf("in the list,5 at position:%d\n",ret);

   //获得表的有效长度
   ret=Get_List_Length(&list);
   printf("the list length is:%d\n",ret);

   
   //销毁表
   UInit_List(&list);
   
}
