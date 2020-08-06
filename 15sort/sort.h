#ifndef _SORT_H_
#define _SORT_H_

#define MAX_STRING 256
#define MAX_SIZE 256

typedef struct
{
	int number;
	int age;
	char name[MAX_STRING];	
}StudentInfo;

typedef StudentInfo RecType;

typedef struct
{
	RecType array[MAX_SIZE];
	int length;
}Sqlist;

void direct_insert_sort(Sqlist *list);
void bubble_sort(Sqlist *list);
void selection_sort(Sqlist *list);
void listTable(Sqlist *list);

#endif