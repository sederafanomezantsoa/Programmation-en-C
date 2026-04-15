#include<stdio.h>
#include<stdlib.h>
#include"headerExcels.h"

int main()
{   
    char nomFichier[100]="personnes_malagasy.csv";
    int nombrePers = compterNombrePersonnelles(nomFichier);
    int numAction = entrerActions();
    if(numAction!=1  &&  numAction!=2)
    {
        numAction = entrerActions();
    }
    if(numAction == 2 )
    {
        int x = AjouterPers(nomFichier,nombrePers);
        nombrePers = x;
    }
    if( numAction == 1)
    {
        Action(nomFichier,nombrePers);
    }

    return 0;
}