#include <errno.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <errno.h>
#include <fcntl.h>

#define LineLength 1000/* max number per line */ 

/* shih*/
void TakeInput(char* str); 
void PrintDir(void); 
int ParseSimple(char* str, char** parsed,char* delim); 
void ExecuteOneCommand(char** parsedArgs); 
void ExecuteAllCommand(char** parsedArgs);
void ExecuteAndCommands(char** parsedArgs);
void ExecuteOrCommands(char** parsedArgs);
void ExecuteRedirected(char** parsedArgs);
void ExecutePiped(char** parsedArgs);
int PathHandler(char** parsed);
void openHelp(void);

//Files 
int IsItFile(char* line);
void DealWithFiles(FILE *fp); /* open a file */ 
void Executing(char* line);

//Check
int CheckPipe(char *line);
int CheckRedirectFile(char *line);
int CheckNext(char *line);
int CheckOr(char *line);
int CheckAnd(char *line);
