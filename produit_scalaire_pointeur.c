#include<stdio.h>
#include<stdlib.h>
int(* entrer(int n))[2];
int produitScalaire(int (*tab)[2], int lignes);
void affichage (int(* tab)[2],int lignes,int reponse);
int entrer_nb_Lignes();


int main()
{
    int lignes = entrer_nb_Lignes();
    int (*tab)[2]=entrer(lignes);
    int reponse_produit = produitScalaire(tab,lignes);
    affichage(tab,lignes,reponse_produit);
}

int(* entrer(int lignes))[2]
{
    int (* tab)[2] = malloc(lignes*sizeof(*tab));
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
