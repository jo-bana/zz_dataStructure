#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
int init(List* L)
{
	if(NULL == L)
	{
   		return RET_ERROR;
	}
	L->AccountList=(ElemType*)malloc(MAX_SIZE*sizeof(ElemType));
	if(!L->AccountList)
	{
		return RET_ERROR;
	}
	L->length = 0;
	return RET_OK;
}

int uninit(List* L)
{
	if(NULL == L)
	{
		return RET_ERROR;
	}
	free(L->AccountList);
	L->AccountList = NULL;
	L->length=0;
	return RET_OK;
}

int add(List* L,ElemType e)
{
	if(NULL==L)
	{
		return RET_ERROR;
	}
	if(L->length>=MAX_SIZE)
	{
		printf("data over flow!\n");
		return RET_OVERFLOW;
	}
	L->AccountList[L->length]=e;
	L->length++;
	return RET_OK;
}
int del(List* L,int pos)
{
	if(NULL == L || pos<0 || pos>=L->length)
	{
 		return  RET_ERROR;
	}
	if(0 == L->length)
	{
		return RET_ERROR;
	}
	int i;
	for(i=pos;i<L->length-1;i++)
	{
		L->AccountList[i]=L->AccountList[i+1];
	}
	L->length--;
	return RET_OK;
	
}
int SearchByItem(List *L,ElemType e)
{
	if(NULL == L)
	{
	return RET_ERROR;
	}
	int i;
	for(i=0;i<L->length;i++)
 {
	//查找用户名
	if(0==strcmp(L->AccountList[i].userName,e.userName))
	{
		if(0==strcmp(L->AccountList[i].passWord,e.passWord))
		{
			return i;
		}
		else
		{
			return RET_PASSWORD_ERROR;
		}
	}
 }
	return RET_NO_ACCOUNT;
}
int SearchByName(List* L,char name[MAX_STRING])
{
	if(NULL==L)
	{
		return RET_ERROR;
	}
	int i;
	for(i=0;i<L->length;i++)
	{
		if(0==strcmp(L->AccountList[i].userName,name))
		{
		return i;
		}
	}
	return RET_NO_ACCOUNT;
}


int printf_list(List* L)
{
	if(NULL==L)
	{
		return RET_ERROR;
	}
	int i;
	for(i=0;i<L->length;i++)
	{
		printf("name:%s password:%s\n",L->AccountList[i].userName,L->AccountList[i].passWord);
	}
 	printf("account list display over!\n");
}



int length(List* L)
{
	if(NULL==L)
	{
		return RET_ERROR;
	}
	return L->length;
}





