
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

// Function to take input
int takeInput(char* str)
{
	char* buf;

	buf = readline("\n>>> ");
	if (strlen(buf) != 0) 
    {
		add_history(buf);
		strcpy(str, buf);
		return 0;
	} 
    else 
    {
		return 1;
	}
}

//deja open ;     fp=fopen("filee.txt","r");

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
  