#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "list.h"

List list;

int initUserList(int flag)
{
	if(0==flag)
	{
		return init(&list);
	}
	else if(1==flag)
	{
		return uninit(&list);
	}
	else
	{
		return RET_ERROR;
	}	
}

int addUser(char *name,char *word)
{
	ElemType tmp;
	int ret;
	if(!name || !word)
	{
		return RET_ERROR;
	}
	strcpy(tmp.userName,name);
	strcpy(tmp.passWord,word);
	ret = add(&list,tmp);
	if(RET_OVERFLOW == ret)
	{
		printf("account list reaches max number!\n");
		return RET_ERROR;
	}
	else if(RET_ERROR == ret)
	{
		printf("account item add failure!\n");
		return RET_ERROR;
	}
	return RET_OK;
}


int chkUser(char* name,char* word)
{
	if(!name || !word)
	{
		return RET_ERROR;
	}
	ElemType tmp;
	memset(&tmp,0,sizeof(tmp));
	strcpy(tmp.userName,name);
	strcpy(tmp.passWord,word);

	int ret = SearchByItem(&list,tmp);
	if(RET_NO_ACCOUNT == ret)
	{
		printf("username error,please input again!\n");
		return RET_ERROR;
	}
	else if(RET_PASSWORD_ERROR == ret)
	{
		return RET_ERROR;
	}
	return RET_OK;
}


int main(void)
{
	int i,ret;
	char name[][MAX_STRING]={"aa","bb","cc","dd"};
	char word[][MAX_STRING]={"aa","bb","cc","dd"};
	char tmpname[MAX_STRING]={0};
	char tmpword[MAX_STRING]={0};

	ret=initUserList(0);/*初始化账户表*/

	for(i=0;i<4;i++)
	{
		ret=addUser(name[i],word[i]);
		continue;
	}
	while(1)
{
	memset(tmpname,0,MAX_STRING*sizeof(char));
	memset(tmpword,0,MAX_STRING*sizeof(char));
	printf("please input Username:");
	gets(tmpname);
	ret=SearchByName(&list,tmpname);/*查找表中是否有tmpname*/
	if(ret<0)
	{
		printf("username error,please input again!\n");
		continue;
	}
	printf("please input password:");
	gets(tmpword);
	ret = chkUser(tmpname,tmpword);
	if(ret<0)
	{
		printf("password error,please input again!\n");
		continue;
	}
	break;		
		
}

printf("your success!\n");/*你成功了！*/

ret=initUserList(1);/*销毁账户表*/
			
}
