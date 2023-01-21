#include"file.h"


void DealWithFiles(FILE *fp)
{
    char ligne[LineLength] ;
    while(!feof(fp))
    {
        fgets(ligne, LineLength, fp);
        ligne[strlen(ligne)-1] = '\0';

        if (strstr(ligne, "quit"))
        {
            break;
        }
        
        Executing(ligne);
        printf("\n%s", ligne);
        printf("\n_____________________________________________________________________________\n");
        memset(ligne,'\0',LineLength);
        sleep(1);
    }
    fclose(fp);
}