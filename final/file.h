

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
//shih
void takeInput(char* str); //lire la ligne de commande
int DealWithFiles(FILE *fp); //open a file
void printDir(); //afficher l'emplacement actuel
int delimiterAvecEspace(char* str, char** parsed); //decouper la ligne de commande
