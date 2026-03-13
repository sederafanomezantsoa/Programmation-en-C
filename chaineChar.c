#include <stdio.h>
#include <stdlib.h>



int main()
{
/* entrer le mot */
    char mot[50];
    int i,n;
    float y,z,w;
    printf("ajouter la chaine : ");
    scanf("%s",&mot);
    n=0;
    for (i=0;i<50;i++)
    {
        if(mot[i]=='\0')
        {
            i=50;
        }
        else
        {
            n=n+1;
            
        } 
    }
printf("nombre Char = : %d \n\n",n);

/* actions sur le mot*/
    z = n/2;
    char x;
    if(floor(z)==z)
    {
        y=z;
    }
    else
    {
        y=floor(z)+1;
    }
    for (i=0;i<y;i++)
    {
        x=mot[n-1-i];
        mot[n-1-i]=mot[i];
        mot[i]=x;
    }

    printf("%s",mot);
}