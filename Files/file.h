
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
/* shih*/
void TakeInput(char* str); /* lire la ligne de commande */ 
void PrintDir(void); /* afficher l'emplacement actuel */
int DelimiterAvecEspace(char* str, char** parsed); /* decouper la ligne de commande */
void ExecuteOneCommand(char** parsedArgs); /* executer une seule commande */
void ExecuteAllCommand(char** parsedArgs);
void ExecuteAndCommands(char** parsedArgs);
void ExecuteOrCommands(char** parsedArgs);
int PathHandler(char** parsed);
void openHelp(void);
int Composee(char* str);

//Files 
int IsItFile(char* line);
void DealWithFiles(FILE *fp); /* open a file */ 
//void Executing(char* line);
