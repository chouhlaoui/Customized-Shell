#include "file.h"
#include<stdio.h>

#define MAXCOM 1000 // max number per line
#define MAXLIST 100 // max number of commands to be supported

int main(void){
char* line;
int NbCmd;
char inputString[MAXCOM], *parsedArgs[MAXLIST];
    int DealWithFiles(FILE *fp); //open a file
    void printDir(); //afficher l'emplacement actuel
    int delimiterAvecEspace(char* str, char** parsed); //decouper la ligne de commande

    while (1)
    {
        printDir();
        takeInput(line);
        NbCmd = delimiterAvecEspace(strdup(line),parsedArgs);
        for (int i = 0; i < NbCmd ; i++) 
        {
		    printf("%s\n",parsedArgs[i]);
	    }
    }
    
    return 0;
  }

