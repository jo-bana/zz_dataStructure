//三条预处理语句的功能：防止该头文件被重复引用
#ifndef _LIST_H_
#define _LIST_H_

#define Max_SIZE 100
#define OK 0
#define ERROR -1

typedef int ElemType; 
typedef struct 
	{
        ElemType *Elem_array;
		int length;
	}List;

//函数声明
int Init_List(List *L);
int UInit_List(List *L);
int Insert_List(List *L,int pos,ElemType e);
int Print_List(List *L);
int Delete_List(List *L,int pos);
int Get_List_Length(List *L);

ElemType Search_List_by_Pos(List *L,int pos);
int Search_List_by_Value(List *L,ElemType e);

#endif