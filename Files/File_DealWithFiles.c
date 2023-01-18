#include"file.h"


void DealWithFiles(FILE *fp)
{
    char ligne[LineLength];
    
    while(!feof(fp))
    {
        fgets(ligne, 100, fp);
        ligne[strlen(ligne)-1] = '\0';

        if (strcmp(ligne, "quit") == 0)
        {
            break;
        }

        sleep(2);
        printf("%s", ligne);
        Executing(ligne);
        printf("\n_____________________________________________________________________________\n");
    }

    fclose(fp);
}