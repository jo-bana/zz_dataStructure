#include <stdio.h>
#include <string.h>
#define MAX_SIZE 256

char* zzstrcpy(char*des,char*source)
{
	if(!des||!source)
	{
		return NULL;
	}
#if 0
	int i;
	for(i=0;soure[i]!='\0',i++)
	{
		des[i]=source[i];
	}
#endif
	char *d=des;
	while((*d++=*source++)!='\0');
	return des;
}

void reverseStr(char *str)
{
	if(!str)
	{
		return;
	}
	int i,j;
	char tmp[MAX_SIZE];	
	char *d=tmp;
	i=strlen(str);
	for(j=i;j>0;j--)
	{	
		d[j]=str[i-j];
	}
	for(j=i;j>0;j--)
	{
		str[j]=d[j];
	}
		
	return;
}


void main()
{
	char a[MAX_SIZE]={0};
	char b[MAX_SIZE]="hello world!";
	printf("a:%s   b:%s\n",a,b);
	zzstrcpy(a,b);
	printf("a:%s   b:%s\n",a,b);
	reverseStr(a);
	printf("a:%s   b:%s\n",a,b);
}
