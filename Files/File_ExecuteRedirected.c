#include"file.h"
void ExecuteRedirected(char** parsedArgs){

	int p;
	char *Command[LineLength] ;
    char *SavingFile[LineLength];

	ParseSimple(strdup(parsedArgs[0]),Command," ");
	ParseSimple(strdup(parsedArgs[1]),SavingFile," ");

    p = fork();

    if (p < 0) 
    {
		printf("\nCould not fork");
	}

	if (p == 0) 
    {
        int File,RedirectedFile;
    
        File = open(SavingFile[0],O_WRONLY | O_CREAT,0777);

        if (File == -1)
        {
            exit(1);
        }
    
        RedirectedFile = dup2(File,STDOUT_FILENO);
        close(File);
        
		if (execvp(Command[0],Command) < 0) 
        {

			printf("\nCould not execute command 2..");
            exit(1);

        }
	} 
    while (wait(NULL)!= -1 || errno != ECHILD );
    
       
}  