#include <stdio.h>
#include "staticString.h"

int init_string(StringType *s)
{
	if(!s)
	{
		return ERROR;
	}
	int i;
	for(i=0;i<MAX_STRING_SIZE;i++)
	{
		s->str[i]=0;
	}
	//memset(s,0,sizeof(StringType))用在二维数组?
	s->length=0;
	return OK;
	
}
int uinit_string(StringType *s)
{
	return init_string(s);	
}
int set_value(StringType *s,char* value,int len)
{
	if(!s||!value||len>MAX_STRING_SIZE)
	{
		return ERROR;
	}
	int i;
	for(i=0;i<len;i++)
	{
		s->str[i]=value[i];		
	}
	s->length = len;
	return OK;
}

int str_concat(StringType *s,StringType *t)//连接
{
	if(!s||!t)
	{
		return ERROR;
	}
	if(s->length+t->length>MAX_STRING_SIZE)
	{
		return ERROR;
	}
	int i;
	for(i=0;i<t->length;i++)
	{
		s->str[s->length+i]=t->str[i];
	}
	s->length+=t->length;			
	
}
int str_sub(StringType *s,int pos,int len,StringType *sub)//主串，位置，长度，存到sub中
{
	if(!s||!sub||pos+len>s->length)
	{
		return ERROR;
	}
	int i;
	for(i=0;i<len;i++)
	{
		sub->str[i]=s->str[pos+i];
	}
	sub->length=len;
	return OK;
}
int str_comp(StringType *s,StringType *t)//比较
{
	if(!s||!t)
	{
		return ERROR;
	}
	int i;
	if(s->length == t->length)
	{
		for(i=0;i<s->length;i++)
		{
			if(s->str[i]!=t->str[i])
			{
				return ERROR;									
			}
		}
		return OK;
    }
	return ERROR;
}
void list(StringType *s)
{
	if(!s)
	{
		return;
	}
	int i;
	for(i=0;i<s->length;i++)
	{
		printf("%c",s->str[i]);
	}
	printf("\n");
	return;
}


