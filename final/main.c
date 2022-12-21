//gcc -o Main -lreadline main.c file.c 

#include "file.h"
#include<stdio.h>

#define MAXCOM 1000 /* max number per line */ 
#define MAXLIST 100 /* max number of commands to be supported */ 

int main(void)
{
  char* line;
  int LineStatus;
  int NbCmd;
  char inputString[MAXCOM], *parsedArgs[MAXLIST];

  while (1)
  {
    PrintDir();
    LineStatus=TakeInput(line);
    if(line=="exit") { 
      break;
      }
    NbCmd = DelimiterAvecEspace(strdup(line),parsedArgs);
    //execvp(parsedArgs[0], parsedArgs);
    /* for (int i = 0; i < NbCmd ; i++) 
    {
      printf("\n%s",parsedArgs[i]);
    } */

  }
    
  return 0;
}

