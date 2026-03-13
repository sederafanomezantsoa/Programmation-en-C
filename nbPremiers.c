#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int testPremier(int n)
{
     int j; int a=0;
    {
     for (j=2;j<n;j++)
    {
     if(floor(n/j)==n/j)
     {
      if(n%j==0)
       {
        a=a+1 ;
       }
     }
     else
      {
       a=0;
      }
      
    } 
    }
    if(a == 0)
        {a=1;}
    else
        {a=0;}
    return a;
}

int main()
{
    int x=0;

    int n=2;
    int N=0;
    
    printf("1\n2\n");
    while (x==0)
    {
      n=n+1;
      if(testPremier(n)==1)
      {
       printf("%d\n",n);
       N=N+1;
      }
      if(N==23)
      {break;}
    }
    return 0;
}