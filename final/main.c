//gcc -o Main -lreadline main.c file.c 

#include "file.h"
#include<stdio.h>
#include<string.h>

#define MAXCOM 1000 /* max number per line */ 
#define MAXLIST 100 /* max number of commands to be supported */ 

int main(void)
{
    char* line;
    int NbCmd;
    char *parsedArgs[MAXLIST];

    while (1)
    {
        PrintDir();
        TakeInput(line);
        NbCmd = DelimiterAvecEspace(strdup(line),parsedArgs);
 	    ExecuteOneCommand(parsedArgs);
    

    }
    
  return 0;
}

