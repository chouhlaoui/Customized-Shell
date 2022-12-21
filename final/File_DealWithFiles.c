#include"file.h"

/*deja open ;     fp=fopen("filee.txt","r");*/ 

int DealWithFiles(FILE *fp)
{
    char ligne[80];

    while(!feof(fp))
    {
        fgets(ligne, 80, fp);
        if (strcmp(ligne, "exit\n") == 0)
        {
            break;
        }
        printf("%s", ligne);
        executer(ligne);
        
    }
    
    printf("\nFINISHED\n");
    fclose(fp);
}
  

