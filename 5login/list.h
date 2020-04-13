#ifndef _LIST_H_
#define _LIST_H_

#define MAX_STRING 256
#define MAX_SIZE   256

#define RET_NO_ACCOUNT      -4
#define RET_PASSWORD_ERROR	-3
#define RET_OVERFLOW 		-2
#define RET_ERROR			-1
#define RET_OK				 0

typedef struct
{
	char userName[MAX_STRING];
	char passWord[MAX_STRING];
	
}Account;

typedef Account ElemType;

typedef struct
{
	ElemType* AccountList;
	int length;
}List;


int init(List* L);
int uninit(List *L);
int add(List *L,ElemType e);
int del(List *L,int pos);
int SearchByItem(List *L,ElemType e);
int SearchByName(List *L,char name[MAX_STRING]);
int printf_list(List *L);
int length(List *L);
#endif