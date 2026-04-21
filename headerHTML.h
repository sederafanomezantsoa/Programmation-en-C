#define Max 1000
typedef struct 
{
    char nom[20];
    char prenom[20];
    char age[20];
    char tel[20];
} Personnelle;

Personnelle personnelle[Max];
void ecrireDansHtml(char *file);
void css();
