#ifndef _STATIC_STRING_H_
#define _STATIC_STRING_H_

#define OK		 0
#define ERROR	-1
#define MAX_STRING_SIZE 256

typedef struct
{
	char str[MAX_STRING_SIZE];
	int length;	
}StringType;

int init_string(StringType *s);
int uinit_string(StringType *s);
int set_value(StringType *s,char* value,int len);
int str_concat(StringType *s,StringType *t);
int str_sub(StringType *s,int pos,int len,StringType *sub);
int str_comp(StringType *s,StringType *t);
void list(StringType *s);


#endif