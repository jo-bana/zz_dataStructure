#include <stdio.h>
#include <string.h>
#include "find.h"

void main()
{
	STable sTable;
	Rec_Type record[]={
			{1,22,"Rose"},
			{5,23,"Gxy"},
			{13,22,"Lb"},
			{19,22,"Psb"},
			{21,23,"Hh"},
			{37,23,"Zyb"},
			{56,25,"Tom"},
			{64,30,"Jim"},
			{75,24,"Lucy"},
			{80,38,"Leon"},
			{88,32,"Jack"},
			{92,54,"Cage"}
		};
	sTable.length=sizeof(record)/sizeof(Rec_Type);
	printf("size = %d\n",sTable.length);
	int i;
	for(i=1;i<=sTable.length;i++)
	{
		sTable.array[i].number=record[i-1].number;
		sTable.array[i].age=record[i-1].age;
		strcpy(sTable.array[i].name,record[i-1].name);
	}
	printf("**********test seqSearch**********\n");
	i=Seq_Search(&sTable,64);
	printf("number=64 record in table %d position\n",i);
	printf("number=64,name=%s,age=%d\n",
		sTable.array[i].name,sTable.array[i].age);
	i=Seq_Search(&sTable,25);
	printf("number=25 record in table %d position\n",i);
	printf("**********test half Search**********\n");
	i=Half_Search(&sTable,64);
	printf("number=64 record in table %d position\n",i);
	printf("number=64,name=%s,age=%d\n",
		sTable.array[i].name,sTable.array[i].age);
	i=Half_Search(&sTable,25);
	printf("number=25 record in table %d position\n",i);
	printf("**********test block Search**********\n");
	Index index[3];
	index[0].maxkey=19;
	index[0].starPos=1;
	index[1].maxkey=64;
	index[1].starPos=5;
	index[2].maxkey=92;
	index[2].starPos=9;
	i=Block_Search(&sTable,64,index,3);
	printf("number=64 record in table %d position\n",i);
	printf("number=64,name=%s,age=%d\n",
		sTable.array[i].name,sTable.array[i].age);

	i=Block_Search(&sTable,25,index,3);
	printf("number=25 record in table %d position\n",i);
	
}
