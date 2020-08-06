#ifndef _HEAP_STRING_H_
#define _HEAP_STRING_H_

#define OK		 0
#define ERROR	-1

typedef struct
{
	char *str;
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