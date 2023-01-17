#include"file.h"
void ShowHistory(void)
{
    int NombreCmdHistorique = 1;

    FILE *fp=fopen("/Users/mac/Desktop/projet/Interpreteur-De-Commande-Shell/Files/History.txt","r");
    
    if (fp==NULL)
    {
        printf("File Not Found");
    }
    
    printf("\n") ;

	while(!feof(fp))
    {
        char* ligne;

        fgets(ligne,200, fp);
        printf("%d) %s \n", NombreCmdHistorique ,ligne);

        NombreCmdHistorique++ ;    
    }
}