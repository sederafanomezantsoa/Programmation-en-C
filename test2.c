#include<stdio.h>
#include<stdlib.h>
#include"Matrice.h"

int main()
{
    int taille = entrerTaille();
    int(*tab1)[taille]=entrerMatrice(taille,1);
    int(*tab2)[taille]=entrerMatrice(taille,2);
    int(*resultat)[taille]=calculProduitMat(taille,tab1,tab2);
    afficher(taille,resultat);
    
return 0;
}
