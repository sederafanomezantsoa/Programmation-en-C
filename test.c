#include<stdio.h>
#include<stdlib.h>
#include"vecteur.h"



int main()
{
    
    int lignes = entrer_nb_Lignes();
    int(*tab)[2] = entrer(lignes);
    int reponse_produit = produitScalaire(tab,lignes);
    affichage(tab,lignes,reponse_produit);
}

