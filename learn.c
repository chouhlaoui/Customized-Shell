/*compiled with gcc -o hello -lreadline learn.c */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#define MAXCOM 1000 /* max number per line */ 
#define MAXLIST 100 /* max number of commands to be supported */ 


int delimiterAvecEspace(char* str, char** parsed)
{
	int i=0;
    parsed[i] = strsep(&str, " ");
    while (parsed[i] != NULL)
    {
       i++;
       parsed[i] = strsep(&str, " ");
    }
    return i;
}

void takeInput(char* str)
{
	char* buf;

	buf = readline("\n>>> ");
	if (strlen(buf) != 0) 
    {
		add_history(buf);
		strcpy(str, buf);
	} 
    
}

int main (void)
{
int NbCmd;
char inputString[MAXCOM], *parsedArgs[MAXLIST];
takeInput(inputString);
 /*char * argv[] = { "ls", "-l", "-n", (char *) NULL };*/
NbCmd=delimiterAvecEspace(strdup(inputString),parsedArgs);
for (int i = 0; i < NbCmd ; i++) {
		printf("%s\n",parsedArgs[i]);
	}
 /*execvp(argv[0], argv);
 //fprintf(stderr, "Erreur %d\n", errno);*/
 return 0;
}