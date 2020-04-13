#include <stdio.h>
#include <stdlib.h>

float maxPrice = 100.0;
 int main(void)
{
    srand((int)time(0));
	int price = 1+(int)(maxPrice*rand()/(RAND_MAX+1.0));

	int ret=0;
	int guessPrice=0;
    printf("price rang:1---%d",(int)maxPrice);
	while(1)
	{
	  printf("please input your guess price:");
	  ret = scanf("%d",&guessPrice);

	  if(0==ret)
        {
        printf("you input error!\n");
	    return ;
	    }

	  if(price == guessPrice)
	  	{
	  	printf("you are best,the price is correct!\n");
		return;
	  	}

	  else if(price<guessPrice)
	  	{
	  printf("your price is higher than really price,please try again!\n");
	  	}

	  else if(price>guessPrice)
	  	{
	  	printf("your price is lower than really price, please try again!\n");
	    }
	}
	
}
