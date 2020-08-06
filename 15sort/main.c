#include <stdio.h>
#include "sort.h"

RecType sInfo[]={
{7,20,"Tom"},
{4,23,"Jim"},
{2,26,"Jack"},
{9,19,"Luck"},
{13,19,"Lily"},
{6,21,"Timmy"},
};

int main(void)
{
	Sqlist p;
	int i;
	for(i=0;i<sizeof(sInfo)/sizeof(RecType);i++)
	{
		p.array[i]=sInfo[i];
	}
	p.length=sizeof(sInfo)/sizeof(RecType);

	listTable(&p);
	//direct_insert_sort(&p);
	//printf("insert sort result:\n");
	//bubble_sort(&p);
	//printf("bubble sort result:\n");
	selection_sort(&p);
	printf("selection sort result:\n");
	listTable(&p);
	
	

}