#include<stdio.h>
#include<stdlib.h>

int (*allouer(int taille))[]
{
    int (* table)[2] = malloc(taille*sizeof(*table));
    return table;
}
int (*entrerMatrice(int taille,int numero))[]
{
    int i,j;
    int(*tab)[taille]=allouer(taille);
    printf("\nAJOUTER LA VALEUR DU MATRICE numero %d :  \n",numero);
    for (i=0;i<taille;i++)
    {
        
        for (j=0;j<taille;j++)
        {
            printf("mat_%d_[ligne %d][colone_%d] ",numero,i+1,j+1);
            scanf("%d",&tab[i][j]);
        }
    }
    return tab;
}
int entrerTaille()
{
    int n;
    printf("entrer la taille :  ");
    scanf("%d",&n);
    return n;
}
int (*calculProduitMat(int taille,int mat1[taille][taille],int mat2[taille][taille]))[]
{
    int i,j,k;
    int x;
    int (*tab3)[taille]=calloc(taille, sizeof (*tab3)); 
    for(i=0;i<taille;i++)
    {
        for(j=0;j<taille;j++)
        {
            for (k=0;k<taille;k++)
            {
                x = mat1[j][k]*mat2[k][i];
                tab3[j][i] = tab3[j][i] + x;
            } 
        }
    }
    return tab3;
}
void afficher(int taille,int matrice[taille][taille])
{
    int i,j;
    printf("\n Le produit de la matrice numero 1 * matrice numero 2 est : \n");
    for (i=0;i<taille;i++)
    {
        for (j=0;j<taille;j++)
        {
            printf("%3d      ",matrice[i][j]);
        }
        printf("\n");
    }
}