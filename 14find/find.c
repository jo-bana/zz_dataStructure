#include "find.h"

//return 0:Ê§°Ü
//return>0:Î»ÖÃÖµ
int Seq_Search(STable *table,Key_Type key)
{
	if(!table)
	{
		return 0;
	}
	int i;
	table->array[0].number=key;
	for(i=table->length;table->array[i].number!=key;i--);
	return i;	
}

int Half_Search(STable *table,Key_Type key)
{
	int low,high,mid;
	low=1;
	high=table->length;
	while(high>=low)
	{
		mid=(low+high)/2;
		if(table->array[mid].number == key)
		{
			return mid;			
		}
		else if(key>table->array[mid].number)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
}
int Block_Search(STable *table,Key_Type key,Index ind[],int len)

{
	if(!table||!ind)
	{
		return 0;
	}
	int i,j;
	table->array[0].number=key;
	for(i=0;i<len;i++)		
	{
		if(key<=ind[i].maxkey)
		{
			//¿éÖĞË³Ğò²éÕÒ
			for(j=ind[i].starPos;(i+1==len)?(j<=table->length):(j<ind[i+1].starPos);j++)
			{
				if(key==table->array[j].number)
				{
					return j;	
				}
			}
			return 0;
		}
		
	}
	return 0;
}


#if 0	
if(key<ind[i].maxkey)
	{		
		for(j=ind[i].starPos;table->array[j].number!=key;j++);
		k=Seq_Search(&table,key);
	}
		return k;
#endif		






