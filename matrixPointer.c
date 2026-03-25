#include<stdio.h>
#include<stdlib.h>

int (*entrerMatrice(int taille,int numero))[];
int entrerTaille();
int (*calculProduitMat(int taille,int mat1[taille][taille],int mat2[taille][taille]))[];
void afficher(int taille,int matrice[taille][taille]);


int main()
{
    int taille = entrerTaille();
    int(*tab1)[taille]=entrerMatrice(taille,1);
    int(*tab2)[taille]=entrerMatrice(taille,2);
    int(*resultat)[taille]=calculProduitMat(taille,tab1,tab2);
    afficher(taille,resultat);
    
return 0;
}
int (*entrerMatrice(int taille,int numero))[]
{
    int i,j;
    int(*tab)[taille]=malloc(taille * sizeof(*tab));
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
    int (*tab3)[taille]=malloc(taille * sizeof (*tab3)); 
    for (i=0;i<taille;i++)
    {
        for (j=0;j<taille;j++)
        {
            tab3[i][j]=0;
        }
    }
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
    for (i=0;i<taille;i++)
    {
        for (j=0;j<taille;j++)
        {
            printf("%3d      ",matrice[i][j]);
        }
        printf("\n");
    }
}