#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "list.h"

List list;//全局变量

//创建或销毁表结构
//flag = 0:创建表
//flag = 1:销毁表
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
	//查找用户名是否冲突
	ret=SearchByName(&list,name);
	if(ret>=0)
	{
		printf("username is already exist!\n");
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

void listAccount()
{
	printf_list(&list);
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
	printf("you input wrong name!\n");
	return RET_ERROR;
}
else if(RET_PASSWORD_ERROR == ret)
{
	printf("you input wrong password!\n");
	return RET_ERROR;
}
return RET_OK;
}

int delUser(char *userName)
{
	if(!userName)
	{
		return RET_ERROR;
	}
	int ret=SearchByName(&list,userName);
	if(ret<0)
	{
		printf("user name error!\n");
		return RET_ERROR;
	}
	return(del(&list,ret));
	
}


int main(void)
{
	char name[MAX_STRING];
	char word[MAX_STRING];
	int ret;
	//初始化账户表
	ret=initUserList(0);
	if(ret<0)
	{
		printf("init failure!\n");
		return;
	}
	//测试数据结构中增加账号的方法
	while(1)
	{
		memset(name,0,MAX_STRING*sizeof(char));
		memset(word,0,MAX_STRING*sizeof(char));
		printf("Add user:\n");
		printf("please input Username:");
		gets(name);
		if(0==strcmp(name,"quit"))
		{
			printf("quit add user test!\n");
			break;
		}
		printf("please input Password:");
		gets(word);
		ret=addUser(name,word);
		if(ret<0)
		{
			printf("add user failure!\n");
		}
		//显示当前用户表
		listAccount();
		
	}

	//测试检查账号的方法
	printf("**************************************\n");
	while(1)
	{
		memset(name,0,MAX_STRING*sizeof(char));
		memset(word,0,MAX_STRING*sizeof(char));
		printf("check user:\n");
		printf("please input Username:");
		gets(name);
		if(0==strcmp("quit",name))
		{
			printf("quit check user test!\n");
			break;
		}
		printf("please input password:");
		gets(word);
		ret = chkUser(name,word);
		if(ret<0)
	  	{
			printf("you input error account!\n");
		}
		else
		{
			printf("you input correct account!\n");

		}
		listAccount();

	
	}

	//测试删除账户的方法
	printf("*****************************************\n");
	while(1)
	{
		memset(name,0,MAX_STRING*sizeof(char));
		memset(word,0,MAX_STRING*sizeof(char));
		printf("Delete user:\n");
		printf("please input username:");
		gets(name);
		if(0 == strcmp(name,"quit"))
	    {
			printf("quit delet user test!\n");
			break;
		}
		ret=delUser(name);
		if(RET_ERROR == ret)
		{
			printf("delete user failure!\n");	
		}
		else
		{
			printf("delete user success!\n");			
		}
		listAccount();
	}

	
	//销毁账户表
	ret=initUserList(1);
	
}
