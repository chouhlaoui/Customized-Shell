#include"file.h"

/*deja open ;     fp=fopen("filee.txt","r");*/ 

void DealWithFiles(FILE *fp)
{
    char ligne[MAXLIST];
    while(!feof(fp))
    {
        fgets(ligne, 80, fp);
        ligne[strlen(ligne)-1] = '\0';
        if (strcmp(ligne, "quit") == 0)
        {
            break;
        }
        sleep(2);
       // printf("%s", ligne);
        Executing(ligne);
        printf("\n_______________________________________\n");
        
    }
    fclose(fp);
}