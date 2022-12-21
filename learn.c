#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void delimiter(char *str,char *argv[])
{
    char* found;
    int i = -1;
    while( (found = strsep(&str," ")) != NULL )
    {
        i++;
        strcpy(argv[i],found);
        printf("%s\n",argv[i]);
   
    }

}


int main (void)
{
 char *argv[]={ (char *) NULL }; 
 //char * argv[] = { "ls", "-l", "-n", (char *) NULL };
 delimiter(strdup("chou dge jdzv-dh hsdb"),argv);
 //execvp(argv[0], argv);
 //fprintf(stderr, "Erreur %d\n", errno);
 return 1;
}