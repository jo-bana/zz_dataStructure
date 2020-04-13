int method2(int maxValue)
{
    if(1==maxValue)   /* Ñø³ÉÏ°¹ß*/
    {
      return 1;
    }
    return(maxValue+method2(maxValue-1));
}
