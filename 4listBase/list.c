#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//函数定义
  int Init_List(List *L)
 {
   if(NULL == L)
   {
      return ERROR;
   }
   //给顺序表分配内存空间
   L->Elem_array=(ElemType*)malloc(Max_SIZE*sizeof(ElemType));
   if(NULL == L->Elem_array)
   {
      return ERROR;
   }
   L->length=0;
   return OK;

}



int UInit_List(List *L)
{
    if(NULL == L)
    {
       return ERROR;
	}
	free(L->Elem_array);
    L->Elem_array=NULL;
	L->length=0;
	return OK;
}
int Insert_List(List *L,int pos ,ElemType e)
{
    if(NULL == L || pos >Max_SIZE || pos<0)
    {
    return ERROR;
	}

	if(Max_SIZE == L->length)
	{
    printf("data over flow!\n");
	return ERROR;
	}
	//插入e
	int i;
	for(i=L->length-1;i>=pos;i--)
	{
	    L->Elem_array[i+1]=L->Elem_array[i];
	}
	L->Elem_array[pos]=e;
	L->length++;
	return OK;
}

int Print_List(List *L)
{
   if(NULL == L)
   	{
      return ERROR;
    }
    printf("the list:\n");

	int i;
	for (i=0;i<L->length;i++)
	{
     printf("%d ",L->Elem_array[i]);
	}

   printf("\n");
   return  OK;
   
 }

 int Delete_List(List *L,int pos)
 {
     if(NULL == L || pos<0 || pos>Max_SIZE)
     {
        return ERROR;
	 }
	 if(0 == L->length)
	 {
        return ERROR;
	 }
     int i;
	 for(i=pos;i<=L->length-1;i++)
	 {
	  L->Elem_array[i]=L->Elem_array[i+1];
	 }
	 L->length--;
	 return OK;
	 
 }

 int Get_List_Length(List *L)
{
	if(NULL==L)
	{
	return ERROR;
 	}
	return L->length;
}


ElemType Search_List_by_Pos(List *L,int pos)
{
	if(NULL==L  || pos<0 || pos>L->length-1)
	{
		return ERROR;
	}
	return L->Elem_array[pos];
	
}

int Search_List_by_Value(List *L,ElemType e)
{
	if(NULL==L)
	{
		return ERROR;
	}
	int i;
	for(i=0;i<L->length;i++)
    {
	if(e==L->Elem_array[i])
		{
		return i;
		}
    }
	return ERROR;
}	




