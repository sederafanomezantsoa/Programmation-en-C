#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,x,n;
    scanf("%d",&n);

    int tab1[n][n];
    int tab2[n][n];
    int tab3[n][n];
 
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            tab3[i][j]=0;
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf(" mat1 : line %d colone %d\t:",i+1,j+1);
            scanf("%d",&tab1[j][i]);
        }
        printf("\n");
    }    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf(" mat2 : line %d colone %d \t:",i+1,j+1);
            scanf("%d",&tab2[j][i]);
        }
        printf("\n");
    }    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                x = tab1[j][k]*tab2[k][i];
                tab3[j][i] = tab3[j][i] + x;
            }  
        }
    }

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d \t",tab3[j][i]);
        }
    printf("\n");
    }
}