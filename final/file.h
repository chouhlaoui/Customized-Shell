
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
/* shih*/
void TakeInput(char* str); /* lire la ligne de commande */ 
void PrintDir(void); /* afficher l'emplacement actuel */
int DelimiterAvecEspace(char* str, char** parsed); /* decouper la ligne de commande */
void ExecuteOneCommand(char** parsedArgs); /* executer une seule commande */
//int Composee(char* str); /* verifier si la ligne contient une composition de commande */
void ExecuteAllCommand(char** parsedArgs);
void ExecuteAndCommands(char** parsedArgs);
void ExecuteOrCommands(char** parsedArgs);
int PathHandler(char** parsed);
void openHelp(void);

//Files 
int IsItFile(char* line);
void DealWithFiles(FILE *fp); /* open a file */ 
void Executing(char* line);


int verifnext(char *line);
int verifand(char *line);
int verifor(char *line);