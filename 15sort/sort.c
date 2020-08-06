#include <stdio.h>
#include "sort.h"
//笔试题的基础，比较好理解的三种，后几种也是需要掌握的

void direct_insert_sort(Sqlist *list)//直接排序法
{
	if(!list)
	{
		return;
	}
	int i,j;
	RecType tmp;

#if 0
	for(i=1;i<list->length;i++)//插多少次，i值代表要插的值
	{
		tmp=list->array[i];//每次要插入的值存在于tmp中
		for(j=i-1;j>=0;j--)//定位待插的表
		{
			if(tmp.number<list->array[j].number)
			{
				list->array[j+1]=list->array[j];
			}
			else
			{
				break;
			}
		}
		if(-1==j)//从头找到尾没找到
		{
			list->array[j+1]=tmp;
		}
	}
#endif

//五步排序
for(i=1;i<list->length;i++)
	{
		tmp=list->array[i];
		for(j=i-1;j>=0&&tmp.number<list->array[j].number;j--)
		{
			list->array[j+1]=list->array[j];
		}
		list->array[j+1]=tmp;
	}
}

void bubble_sort(Sqlist *list)//冒泡排序法
{
	if(!list)
	{
		return;
	}
	int i,j;
	RecType tmp;
	for(i=0;i<list->length-1;i++)
	{
		for(j=0;j<list->length-i-1;j++)
		{
			if(list->array[j].number>list->array[j+1].number)/*如果大的值在小的值前面就要交换*/
			{				
				tmp=list->array[j];
				list->array[j]=list->array[j+1];
				list->array[j+1]=tmp;
			}
		}
	}
}
void selection_sort(Sqlist *list)
{
	int i,j;
	int k;  //位置值
	RecType tmp;
	for(i=0;i<list->length-1;i++)//需要做几轮找最大最小的动作
	{
		k=i;
		for(j=i+1;j<list->length;j++)//从次位开始找，找到最后
		{
			if(list->array[k].number>list->array[j].number)
			{
				k=j;				
			}
		}
		if(k!=i)//如果改位置就是发生了交换
		{
			tmp=list->array[k];
			list->array[k]=list->array[i];
			list->array[i]=tmp;
		}
	}

}//选择排序法
void listTable(Sqlist *list)
{
	if(!list)
	{
		return;
	}
	int i;
	for(i=0;i<list->length;i++)		
	{
		printf("No.:%d age %d name %s\n",list->array[i].number,list->array[i].age,list->array[i].name);		
	}
	printf("*********************************************************************\n");

}

