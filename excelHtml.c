#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"headerHTML.h"
Personnelle personnelle[Max];

void css()
{
    FILE *style =fopen("style1.css","w");
    fprintf(style,"h1 { color : red}");
    fprintf(
        style,
        "div.colone{"
            "color : white;"
            "width : 150px;"
            "color : #030303;"
            "position : flex;"
            "display : inline-block;"
            "border : 1px solid green;"
        "}"
        "div.contenue"
        "{"
            "display : inline-block;"
            "background-color : white;"
        "}"
        "div.colone1"
        "{"
            "position : flex;"
            "display : inline-block;"
            "color : red;"
            "width : 150px;"
            "border : 1px solid green;"
        );
        
    fclose(style);
}
void ecrireDansHtml(char *file)
{
    FILE *data = fopen(file,"r");
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

/*----------------------------------------------------------------*/
    FILE *new_data = fopen("index.html","w");
    fprintf(new_data, 
        "<html>\n"
            "<header>"
                "<link rel='stylesheet' href='style1.css'>"
            "</header>"
        "<body>\n");
        
    fprintf(new_data, "<h1>Données personnelles</h1>\n");
    fprintf(new_data,"<div class=\"contenue\">");
            fprintf(new_data,
        "<div class =\"ligne\">"
            "<div class=\"colone1\">nom</div>" 
            "<div class=\"colone1\">prenom</div>"
            "<div class=\"colone1\">age</div>"
            "<div class=\"colone1\">tel</div>"
        "</div>\n"
            );
    for (i = 1; i < 21 ; i++)
    {
        fprintf(new_data,
        "<div class =\"ligne\">"
            "<div class=\"colone\">%s</div>" 
            "<div class=\"colone\">%s</div>"
            "<div class=\"colone\">%s</div>"
            "<div class=\"colone\">%s</div>"
        "</div>\n",
        personnelle[i].nom,personnelle[i].prenom,personnelle[i].age,personnelle[i].tel);            

    }
    fprintf(new_data,"<div>");
    fprintf(new_data, "</body>\n</html>");
    fclose(new_data);
}