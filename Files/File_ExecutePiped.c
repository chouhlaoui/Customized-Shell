#include"file.h"

void ExecutePiped(char** parsedArgs,int N)
{
if(N==2)
{
	int p1, p2;
    int fd[2];

    char *CommandOne[LineLength] ;
    char *CommandTwo[LineLength];

	ParseSimple(strdup(parsedArgs[0]),CommandOne," ");
	ParseSimple(strdup(parsedArgs[1]),CommandTwo," ");

    if (pipe(fd) < 0) 
    {
		printf("\nPipe could not be initialized");
	}
   
    p1 = fork();
    
	if (p1 < 0) {
		printf("\nCould not fork");
	}
    
    if (p1 == 0) 
    {
        dup2(fd[1],STDOUT_FILENO);
        close(fd[1]);
        close(fd[0]);

        if (execvp(CommandOne[0], CommandOne) < 0) 
        {
			printf("\nCould not execute command ..");
            exit(1);
		}
        
	} 
    p2=fork();
    
    if (p2 < 0) {
		printf("\nCould not fork");
	}

    if (p2 == 0) 
    {
        dup2(fd[0],STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);

        if (execvp(CommandTwo[0], CommandTwo) < 0) 
        {
			printf("\nCould not execute piping command ..");
            exit(1);
		}
        
	} 


    close(fd[1]);
    close(fd[0]);
    waitpid(p1,NULL,0);
    waitpid(p2,NULL,0);
}
else{
    printf("An inadequate number of arguments in the command prompt");
}   
}