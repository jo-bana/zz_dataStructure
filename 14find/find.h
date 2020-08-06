#ifndef _FIND_H_
#define _FIND_H_


#define MAX_LENGTH	256
#define MAX_STRING	256

typedef struct
{
	int number;
	int age;
	char name[MAX_STRING];
}student_info;

typedef student_info Rec_Type;
typedef int Key_Type;

typedef struct
{
	Rec_Type array[MAX_LENGTH];
	int length;
}STable;

typedef struct
{
	Key_Type maxkey;
	int starPos;
}Index;

int Seq_Search(STable *table,Key_Type key);
//Half_Search
//Block_Search
int Half_Search(STable *table,Key_Type key);
int Block_Search(STable *table,Key_Type key,Index ind[],int len);


#endif