#include"file.h"
//Execute cmd1||cmd2
void ExecuteOrCommands(char** parsedArgs){

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

	if (p1 == 0) {
        
		if (execvp(CommandOne[0],CommandOne) < 0) {
            p2 = fork();
            if (p2 == 0) 
            {
                if (execvp(CommandTwo[0], CommandTwo) < 0) 
                {
			        printf("\nCould not execute command 2..");
                    exit(0);
    		    }
            }
            else 
            {
                wait(NULL);
	        }
            exit(0);
        }
	} 
    while (wait(NULL)!= -1 || errno != ECHILD );
    
       
}  