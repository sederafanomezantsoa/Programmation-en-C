#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"headerExcels.h"
Personnelle personnelle[MAX];


int AjouterPers(char  file[100],int nombrePers)
{
    FILE *data;
    data = fopen(file,"a");
    char nom[20];
    char prenom[20];
    char contact[20];
    int age;
    printf("ajouter une autre personnes \n");
    printf("nom :  ");
    scanf("%s",nom);
    printf("prenom :  ");
    scanf("%s",prenom);
    printf("age :  ");
    scanf("%d",&age);
    printf("contact :  ");
    scanf("%s",contact);
    printf("%s    %s    %d   %s ",nom,prenom,age,contact);
    fprintf(data,"%s,%s,%d,%s\n",nom,prenom,age,contact);
    fclose(data);
    nombrePers= nombrePers + 1;
    entrerActions ();
    return nombrePers;
}
void Action(char file[100],int nombrePersonnelles)
{
    FILE *data;
    data = fopen(file,"r");   

    /**************************************************************************/

    char (*ligne)[100]=malloc(1000*sizeof(ligne));
    int i = 0;
    while(fgets(ligne[i],sizeof(ligne[i]),data) && i<21)
    {
        printf("____________ligne[%d]________________ \n",i);
        printf("%s\n",ligne[i]);
        char *token;
        token = strtok(ligne[i],",");
        if(token)
        {
            strcpy(personnelle[i].nom,token);
            //printf("token nom Ok\n");
           // printf("%s\n",personnelle[i].nom);
        }
        token = strtok(NULL,",");
        if(token)
        {
            strcpy(personnelle[i].prenom,token);
            //printf("token prenom Ok\n");
            //printf("%s\n",personnelle[i].prenom);
            
        }
        token = strtok(NULL,",");
        if(token)
        {
            strcpy(personnelle[i].age,token);
            //printf("token age Ok\n");
           // printf("%s\n",personnelle[i].age);
        }
        token = strtok(NULL,",");
        if(token)
        {
            strcpy(personnelle[i].tel,token);
           // printf("token tel Ok Ok\n");
            //printf("%s\n",personnelle[i].tel);
        }                
        i++;
    }
    fclose(data);

    /*****************************************************************************/

    printf("______________noms inclus______________\n");
    for (i = 0; i < nombrePersonnelles ; i++)
    {
        printf("%s\n",personnelle[i].nom);
    }
    printf("______________présentation terminé______________\n");

    printf("\n/*****************************************************************************/\n\n");

    printf("______________entrons dans l'actions______________\n");
    char *entrerNom = malloc(50*sizeof(char));
    printf("rechercher par nom :  ");
    scanf("%s",entrerNom);
    i=0;
    char * choixModifier = malloc(50*sizeof(char));
    //int ilEstLa=0;
    for (i = 0; i < nombrePersonnelles ; i++)
    {
        if(strcmp(entrerNom,personnelle[i].nom)==0)
        {
            printf(" %s est dans nos personnelles\n",entrerNom);
            printf(" nom : %s\n prenom : %s\n",personnelle[i].nom,personnelle[i].prenom);
            printf(" age : %s %s est %s ans\n",personnelle[i].nom,personnelle[i].prenom,personnelle[i].age);
            printf(" pour le(la) contacter vueillez appelez 0%s\n",personnelle[i].tel);
            printf("/*******************************************************************************/\n");
            printf("Modifier le data de %s ?  reponds oui ou non :  ",personnelle[i].nom);
            scanf("%s",choixModifier);
            printf("/*******************************************************************************/\n");
            int test = 0;
            while (test == 0)
            {
                if(strcmp(choixModifier,"oui")==0)
                {
                    Modifications(file,personnelle[i].nom,nombrePersonnelles);
                    test = 1;
                }
                if(strcmp(choixModifier,"non")==0)
                {
                    printf("autre actions ou entrer pour quiter");
                    entrerActions();
                    test = 1;
                }
            }

           // ilEstLa = 1;
        }
        
    }

/*****************************************************************************/
}

void Modifications(char file[100],char * nom,int nombrePers)
{
    FILE *data; 
    data = fopen(file,"r");
    char (*ligne)[100]=malloc(1000*sizeof(ligne));
    int i = 0;
/*******************************************************************************/
    while(fgets(ligne[i],sizeof(ligne[i]),data) && i<21)
    {
        //printf("____________ligne[%d]________________ \n",i);
        //printf("%s\n",ligne[i]);
        char *token;

        token = strtok(ligne[i],",");
        if(token)
        {
            strcpy(personnelle[i].nom,token);
            //printf("token nom Ok\n");
            //printf("%s\n",personnelle[i].nom);
        }
        token = strtok(NULL,",");
        if(token)
        {
            strcpy(personnelle[i].prenom,token);
            //printf("token prenom Ok\n");
            //printf("%s\n",personnelle[i].prenom);
            
        }
        token = strtok(NULL,",");
        if(token)
        {
            strcpy(personnelle[i].age,token);
            //printf("token age Ok\n");
            //printf("%s\n",personnelle[i].age);
        }
        token = strtok(NULL,",");
        if(token)
        {
            strcpy(personnelle[i].tel,token);
            //printf("token tel Ok Ok\n");
            //printf("%s\n",personnelle[i].tel);
        }                
        i++;

    }
    fclose(data);
    free(data);
    free(ligne);
    
/*******************************************************************************/
    int nombrePersonnelles=nombrePers;
    for (i = 0; i < nombrePersonnelles ; i++)
    {
        if(strcmp(personnelle[i].nom,nom)==0)
        {
            printf("/*******************************************************************************/\n");
            printf("vous voulez modifier le données de %s %s\n",personnelle[i].nom,personnelle[i].prenom);
            printf("entrer le nom corrigé de %s  :   ",personnelle[i].nom);
            scanf("%s",personnelle[i].nom);
            printf("prenom corrigé :   ");
            scanf("%s",personnelle[i].prenom);
            printf("age corrigé :   ");
            scanf("%s",personnelle[i].age);
            printf("numero corrigé :   ");            
            scanf("%s",personnelle[i].tel);
            strcpy(personnelle[i].tel,strcat(personnelle[i].tel,"\n"));
        printf("/*******************************************************************************/\n");
            printf("nouveau données de %s\n",personnelle[i].nom);
            printf("nom : %s\n prenom : %s\n",personnelle[i].nom,personnelle[i].prenom);
            printf("age : %s %s est %s ans\n",personnelle[i].nom,personnelle[i].prenom,personnelle[i].age);
            printf("tel :  %s\n",personnelle[i].tel);
            
        }
    }
    data = fopen("versionModifiée12.csv","w");
    for (i = 0; i < nombrePersonnelles ; i++)
    {

        fprintf(data,"%s,%s,%s,%s",personnelle[i].nom,personnelle[i].prenom,personnelle[i].age,personnelle[i].tel);
    }
    fclose(data);
    entrerActions(); 
    printf("________fin____________");
}
int compterNombrePersonnelles(char file[100])
{
    FILE * data = fopen(file,"r");
    int i=0;
    int j=0;
    int nombrePersonnelle = -1;
    char (*ligne)[100]=malloc(10000*sizeof(*ligne));
    while(j==0)
    {
        fgets((ligne[i]),sizeof(ligne[i]),data);
        if(strcmp(ligne[i],"")==0 )
        {
            j=1;
        }
        i++;
        nombrePersonnelle ++;
    }    
    printf("\n-------------------------\nnombre de personnelles %d\n----------------------------\n",nombrePersonnelle);
    return nombrePersonnelle;
}
int entrerActions()
{
    int n;
    printf("1 pour rechercher par nom et modifier\n");
    printf("2 pour ajouter un autre personnelle\n");
    printf("entrer 1 ou 2 :  ");
    scanf("%d",&n);
    return n;
}