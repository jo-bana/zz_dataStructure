#include <stdio.h>
#include <sys/time.h>

#define N 1000
#define STRING_LEN 256
void O1swap()
{
int a=10,b=20,tmp=0;
	tmp=a;
	a=b;
	b=tmp;
}

void OnSum()
{
long sum=0,i;
for (i=0;i<N;i++)
   {
    sum+=i;
   }
}

void OnnCount()
{
int i,j,x=0;
for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
        x++;
	}
  }
}

void OnnnCount()
{
 int i,j,k;
 long long x=0; 
 for(i=0;i<N;i++)
  {
   for(j=0;j<N;j++)
  	 {
  	   for(k=0;k<N;k++)
  	    {
  	      x++;
  	    }
  	 }
   }
}

 void OlnSum()
{
     int i=1;
	 while(i<=N)
	 {
	   i*=2;
	 }

}


void OnlnSum()
{
     int num1,num2,i,j;
	 for(i=0;i<N;i++)
	 {
        num1+=1;
	    for(j=1;j<N;j*=2)
   	    {
         num2+=num1;
	    }

	 }
	 
	 

}

int main(void)
{
    long timeUse=0;
    struct timeval tvStart,tvEnd;
    //O(1)测试
	//记录开始时间
    gettimeofday(&tvStart,NULL);
	O1swap();
	//记录结束时间
	gettimeofday(&tvEnd,NULL);
	//计算所用时间
	timeUse=(tvEnd.tv_sec*1000*1000+tvEnd.tv_usec)-(tvStart.tv_sec*1000*1000+tvStart.tv_usec);	
    printf("O(1) use time = %ld\n",timeUse);

    //O(n)测试
    gettimeofday(&tvStart,NULL);
	OnSum();
	//记录结束时间
	gettimeofday(&tvEnd,NULL);
	//计算所用时间
	timeUse=(tvEnd.tv_sec*1000*1000+tvEnd.tv_usec)-(tvStart.tv_sec*1000*1000+tvStart.tv_usec);	
    printf("O(n) use time = %ld\n",timeUse);

	//O(n2)测试
	gettimeofday(&tvStart,NULL);
	OnnCount();
	//记录结束时间
	gettimeofday(&tvEnd,NULL);
	//计算所用时间
	timeUse=(tvEnd.tv_sec*1000*1000+tvEnd.tv_usec)-(tvStart.tv_sec*1000*1000+tvStart.tv_usec);	
    printf("O(n2) use time = %ld\n",timeUse);

	//O(n3)测试
	gettimeofday(&tvStart,NULL);
	OnnnCount();
	//记录结束时间
	gettimeofday(&tvEnd,NULL);
	//计算所用时间
	timeUse=(tvEnd.tv_sec*1000*1000+tvEnd.tv_usec)-(tvStart.tv_sec*1000*1000+tvStart.tv_usec);	
    printf("O(n3) use time = %ld\n",timeUse);

	//O(log2n)测试
	gettimeofday(&tvStart,NULL);
	OlnSum();
	//记录结束时间
	gettimeofday(&tvEnd,NULL);
	//计算所用时间
	timeUse=(tvEnd.tv_sec*1000*1000+tvEnd.tv_usec)-(tvStart.tv_sec*1000*1000+tvStart.tv_usec);	
    printf("O(log2n) use time = %ld\n",timeUse);

	//O(nlog2n)测试
	gettimeofday(&tvStart,NULL);
	OnlnSum();
	//记录结束时间
	gettimeofday(&tvEnd,NULL);
	//计算所用时间
	timeUse=(tvEnd.tv_sec*1000*1000+tvEnd.tv_usec)-(tvStart.tv_sec*1000*1000+tvStart.tv_usec);	
    printf("O(nlog2n) use time = %ld\n",timeUse);
    return 0;
}

