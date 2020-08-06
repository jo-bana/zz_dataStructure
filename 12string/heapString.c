#include <stdio.h>
#include <stdlib.h>
#include "heapString.h"

int init_string(StringType *s)
{
	if(!s)
	{
		return ERROR;
	}
	s->str=NULL;
	s->length=0;
	return OK;
}
int uinit_string(StringType *s)
{
	if(!s)
	{
		return ERROR;
	}
	if(NULL==s->str)
	{
		return OK;
	}
	free(s->str);
	s->str=NULL;
	s->length=0;
	return OK;	
}
int set_value(StringType *s,char* value,int len)
{
	if(!s||!value||len<0)
	{
		return ERROR;
	}
	int i;
	if(NULL!=s->str)
	{
		free(s->str);	
		s->str=NULL;
		s->length=0;
	}
	s->str=(char*)malloc(len*sizeof(char));
	if(!s->str)
	{
		printf("malloc error!\n");
		return ERROR;
	}
	for(i=0;i<len;i++)
	{
		s->str[i]=value[i];		
	}
	s->length=len;
	return OK;	
}
int str_concat(StringType *s,StringType *t)
{
	if(!s||!t)
	{
		return ERROR;
	}
	int i;
	char *tmp;
	tmp=(char*)malloc(sizeof(char)*s->length);
	if(!tmp)
	{
		printf("malloc error!\n");
		return ERROR;		
	}

	for(i=0;i<s->length;i++)
	{
		tmp[i]=s->str[i];		
	}
	free(s->str);
	s->str=(char*)malloc(sizeof(char)*(t->length+s->length));
	if(!s->str)
	{
		printf("malloc error!\n");
		return ERROR;
	}
	for(i=0;i<s->length;i++)
	{
		s->str[i]=tmp[i];
	}
	
	for(i=0;i<t->length;i++)
	{
		s->str[s->length+i]=t->str[i];
	}
	s->length=s->length+t->length;
	free(tmp);
	return OK;
}
 int str_sub(StringType *s,int pos,int len,StringType *sub)//主串，位置，长度，存到sub中
{
	if(!s||!sub||pos<1||pos+len>s->length)//pos>s->length||len>s->length-pos+1 有点问题
	{
		return ERROR;
	}
	if(sub->str) //健壮性考虑
	{
		free(sub->str);
		sub->str=NULL;
		sub->length=0;
	}
	int i;
/*	if(!s->length)  //加分点
	{
		return ERROR;
	}
*/ 
	sub->str=(char*)malloc(sizeof(char)*(len));
	if(!sub->str)
	{
		return ERROR;	
	}
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

