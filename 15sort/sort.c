#include <stdio.h>
#include "sort.h"
//������Ļ������ȽϺ��������֣�����Ҳ����Ҫ���յ�

void direct_insert_sort(Sqlist *list)//ֱ������
{
	if(!list)
	{
		return;
	}
	int i,j;
	RecType tmp;

#if 0
	for(i=1;i<list->length;i++)//����ٴΣ�iֵ����Ҫ���ֵ
	{
		tmp=list->array[i];//ÿ��Ҫ�����ֵ������tmp��
		for(j=i-1;j>=0;j--)//��λ����ı�
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
		if(-1==j)//��ͷ�ҵ�βû�ҵ�
		{
			list->array[j+1]=tmp;
		}
	}
#endif

//�岽����
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

void bubble_sort(Sqlist *list)//ð������
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
			if(list->array[j].number>list->array[j+1].number)/*������ֵ��С��ֵǰ���Ҫ����*/
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
	int k;  //λ��ֵ
	RecType tmp;
	for(i=0;i<list->length-1;i++)//��Ҫ�������������С�Ķ���
	{
		k=i;
		for(j=i+1;j<list->length;j++)//�Ӵ�λ��ʼ�ң��ҵ����
		{
			if(list->array[k].number>list->array[j].number)
			{
				k=j;				
			}
		}
		if(k!=i)//�����λ�þ��Ƿ����˽���
		{
			tmp=list->array[k];
			list->array[k]=list->array[i];
			list->array[i]=tmp;
		}
	}

}//ѡ������
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

