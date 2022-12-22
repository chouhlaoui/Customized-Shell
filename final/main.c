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
    PrintDir();
	TakeInput(inputString);
    if(strcmp(inputString,"exit")!=0)
    {
        NbCmd=DelimiterAvecEspace(strdup(inputString),parsedArgs);
        if (PathHandler(parsedArgs)==0)
        {
           switch (Composee(inputString))
        {
        case 1:
            printf(";");
            break;
        case 2:
            printf("||");
            break;
        case 3:
            printf("&&");
            break;
        default:
            ExecuteOneCommand(parsedArgs);
 	        //fprintf(stderr, "Erreur %d\n", errno);
            break;
        }
        }
        
        


    }
    else 
    {
        break;
    }
	
}


 return 0;
}