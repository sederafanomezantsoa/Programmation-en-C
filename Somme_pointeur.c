#include<stdio.h>
#include<stdlib.h>
int* entrer();
int SOMME(int tab[]);
void affichage_somme(int S);
int main()
{
    int* tab = entrer();
    int S = SOMME(tab);
    affichage_somme(S);
}

int* entrer()
{
    int* tab = malloc(2*sizeof(int));
    int i;
    for (i=0;i<2;i++)
    {
        printf("entrer la valeur %d : ",i);
        scanf("%d",&tab[i]);
    }
    return tab;
}
 
int SOMME(int tab[2])
{
    int somme;
    somme = tab[0]+tab[1];
    return somme;
}

void affichage_somme(int S)
{ 
    printf("la somme est S = %d",S);
}
