#include<stdio.h>
#include<stdlib.h>

int main()
{	
    int n=0,somme ;
	int tab[100] ;
	tab[0] =  3 ;
    tab[1] = -4 ;
    somme = tab[0] + tab[1];

    
	for ( n=2;n<70;n++ )
    {
        tab[n]= (2*tab[n-1]) + (3*tab[n-2]) ;
        if(n==69)
        {
            printf(" la valeur du Vn au rang 70 est %d \n",tab[69]);
        }
        else if (n<30)
        {
            somme = somme + tab[n];
        }
    }
    printf(" la somme de V1 à V30 est : %d \n",somme);
return 0 ;
}
