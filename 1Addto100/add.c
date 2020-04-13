#include <stdio.h>
#define N 100   //const int N=100;
int main(void)
{
    int sum=0;
	//用1号函数解决累加和问题
	sum=method1(N);
	printf("method1:1 to %d sum:%d\n",N,sum);
	//用2号函数解决累加和问题
	sum=method2(N);
	printf("method2:1 to %d sum:%d\n",N,sum);
	//用3号函数解决累加和问题
	sum=method3(N);
	printf("method3:1 to %d sum:%d\n",N,sum);
}
int method1(int maxValue)/*for循环*/
{
    int s=0,i=0;	
	for(i=1;i<=maxValue;i++)
    {
       s+=i;      //s=s+i
	}
	return s;
}

int method2(int maxValue)/*递归*/
{
    if(1==maxValue)   /* 养成习惯*/
    {
      return 1;
    }
    return(maxValue+method2(maxValue-1));
}

int method3(int maxValue)/*公式*/
{
return maxValue*(maxValue+1)/2;
}

