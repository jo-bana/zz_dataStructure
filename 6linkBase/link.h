#ifndef _LINK_H_
#define _LINK_H_

#define OK 		0
#define ERROR  -1

typedef int ElemType;

//定义链表的节点
typedef struct LNode
{
	ElemType data;		//数据域
	struct LNode *next;	//指针域
}LNode;

int create_LinkList(LNode* L);    		//正向创建列表
int Rcreate_LinkList(LNode* L);			//逆向创建列表
int Insert_LNode(LNode* L,int pos,ElemType e);
int Delete_LNode(LNode* L,int pos);
ElemType Search_by_pos(LNode* L,int pos);
LNode*  Search_by_data(LNode* L,ElemType e);
int Get_length(LNode* L);
int destory_LinkList(LNode* L);
int printf_Link(LNode* L);


#endif

