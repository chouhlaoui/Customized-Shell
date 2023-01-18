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

#define LineLength 1000

void PrintDir(void); 
int TakeInput(char* str); 
int ParseSimple(char* str, char** parsed,char* delim); 

int PathHandler(char** parsed);
void openHelp(void);
void ShowHistory(void);


int IsItFile(char* line);
void DealWithFiles(FILE *fp);


void Executing(char* line);
void ExecuteOneCommand(char** parsedArgs); 
void ExecuteAllCommand(char** parsedArgs,int n);
void ExecuteAndCommands(char** parsedArgs,int N);
void ExecuteOrCommands(char** parsedArgs,int N);
void ExecuteRedirected(char** parsedArgs,int N);
void ExecutePiped(char** parsedArgs,int N);


int CheckPipe(char *line);
int CheckRedirectFile(char *line);
int CheckNext(char *line);
int CheckOr(char *line);
int CheckAnd(char *line);


