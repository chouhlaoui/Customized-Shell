#include"file.h"
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



int main (void)
{
int NbCmd;
char inputString[MAXCOM], *parsedArgs[MAXLIST];
while (1)
{

	TakeInput(inputString);
	NbCmd=DelimiterAvecEspace(strdup(inputString),parsedArgs);
	for (int i = 0; i < NbCmd ; i++) {
		printf("%s\n",parsedArgs[i]);
	}
	printf("%d\n",NbCmd);
 	execute(parsedArgs);
 	//fprintf(stderr, "Erreur %d\n", errno);
}


 return 0;
}