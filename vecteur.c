#include<stdio.h>
#include<stdlib.h>


int (* allouer(int lignes))[2]
{
    int (* table)[2] = malloc(lignes*sizeof(*table));
    return table;
}

int (* entrer(int lignes))[2]
{
    int (* tab)[2] = allouer(lignes);
    int i,j;
    for(j=0;j<2;j++)
    {
        for(i=0;i<lignes;i++)
        {
            printf("entrer la valeur du vecteur %d ligne %d  ",j+1,i+1);
            scanf("%d",&tab[i][j]);
        }
        printf("\n");
    }

    return tab;
}
int produitScalaire(int (*tab)[2], int lignes)
{
    int i;
    int reponse = 0;
        for (i=0;i<lignes;i++)
    {
        reponse = reponse + (tab[i][0] * tab[i][1]);
    }
    return reponse;
}
int entrer_nb_Lignes()
{
    int nb_Lignes;
    printf("entrer le nombre de ligne du vecteur   : ");
    scanf("%d",&nb_Lignes); 
    return nb_Lignes;
    
}
void affichage (int(* tab)[2],int lignes,int reponse)
{
    int i,j;
    for (i=0;i<lignes;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d   ",tab[i][j]);
        }
        printf("\n");
    }

    printf("\nle produit scalaire de ces vecteurs est : %d \n\n\n",reponse);

}