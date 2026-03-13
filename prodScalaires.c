#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{	
	int i,n,x;
	x=0;
	printf("dimension : ");
	scanf("%d",&n);
	int tab1[n]; 
	int tab2[n]; 

	for (i=0;i<n;i++)
	{
		printf("vecteur 1 ligne %d ",tab1[i]+1);
		scanf("%d",&tab1[i]);
	}
	for (i=0;i<n;i++)
	{
		printf("vecteur 2 ligne %d ",tab2[i]+1);
		scanf("%d",&tab2[i]);
	}
	for (i=0;i<n;i++)
	{
		x=x + (tab1[i]*tab2[i]);
	}
	printf(" le produit scalaire est  %d",x);
	return 0;
}	