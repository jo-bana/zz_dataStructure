#include <stdio.h>
#include <string.h>
//#include "staticString.h"
#include "heapString.h"

char  string1[]="Class 1 students";
char  string2[]="Class 2 students";

int main(void)
{
	StringType x,y;
	StringType sub;
	init_string(&sub);
	init_string(&x);
	init_string(&y);

	set_value(&x,string1,strlen(string1));//复制，地址，数组，长度
	set_value(&y,string2,strlen(string2));

	printf("x string:");
	list(&x);

	printf("y string:");
	list(&y);
	
	if(OK==str_comp(&x,&y))
	{
		printf("%s and %s match!\n",x.str,y.str);
	}
	else
	{
		printf("%s and %s not match!\n",x.str,y.str);	
	}
	
	printf("%s and %s %s!\n",x.str,x.str,(OK==str_comp(&x,&x)?"match":"not match"));

	str_concat(&x,&y);
	list(&x);
	list(&y);

	str_sub(&x,5,7,&sub);
	list(&sub);
	uinit_string(&x);
	uinit_string(&y);
	uinit_string(&sub);
	
}

