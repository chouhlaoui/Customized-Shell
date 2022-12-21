
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
/* shih*/
int TakeInput(char* str); /* lire la ligne de commande */ 
void DealWithFiles(FILE *fp); /* open a file */ 
void PrintDir(); /* afficher l'emplacement actuel */
int DelimiterAvecEspace(char* str, char** parsed); /* decouper la ligne de commande */


