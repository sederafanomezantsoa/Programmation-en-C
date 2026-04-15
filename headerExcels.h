#define MAX 1000
typedef struct 
{
    char nom[100];
    char prenom[100];
    char age[10];
    char tel[20];
} Personnelle;

extern Personnelle personnelle[MAX];


int AjouterPers(char  file[100],int nombrePers);
void Action(char file[100],int nombrePersonnelles);
void Modifications(char file[100],char * nom,int nombrePers);
int compterNombrePersonnelles(char file[100]);
int entrerActions();