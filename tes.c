#include<stdio.h>
#include<string.h>
int main()
{
    char ligne[80];
    FILE *fp;
    fp=fopen("filee.txt","r");

    while(!feof(fp))
    {
        fgets(ligne, 80, fp);
        if (strcmp(ligne, "exit\n") == 0)
        {
            break;
        }
        printf("%s", ligne);
        
    }
    
    printf("\nFINISHED\n");
    fclose(fp);
    return 0;
}
  