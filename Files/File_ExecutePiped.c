#include"file.h"

void ExecutePiped(char** parsedArgs,int N)
{
if(N==2)
{
	int p1, p2;
    int fd[2];
    int Executed[2];

    char *CommandOne[LineLength] ;
    char *CommandTwo[LineLength];

	ParseSimple(strdup(parsedArgs[0]),CommandOne," ");
	ParseSimple(strdup(parsedArgs[1]),CommandTwo," ");

    if (pipe(fd) < 0) 
    {
		printf("\nPipe could not be initialized");
	}

    if (pipe(Executed) < 0) 
    {
		printf("\nPipe could not be initialized");
	}

    p1 = fork();
    
	if (p1 < 0) 
    {
		printf("\nCould not fork");
	}
    
    if (p1 == 0) 
    {
        dup2(fd[1],STDOUT_FILENO);
        close(fd[1]);
        close(fd[0]);

        int CommandState;
        close(Executed[0]);

        if (execvp(CommandOne[0], CommandOne) < 0) 
        {
			printf("\nCould not execute command ..");
            CommandState = 0;
            write(Executed[1],&CommandState,sizeof(CommandState));
            close(Executed[1]);
            exit(1);
		}
        
	} 

    int ReceivedState = 1;
    close(Executed[1]);

	if (read(Executed[0],&ReceivedState,sizeof(ReceivedState))==-1)
	{
		ReceivedState=1;
	}

	close(Executed[0]);
  
    if(ReceivedState==1)
    {
          
        p2=fork();
    
        if (p2 < 0) 
        {
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

    }
    else
    {
        printf("pipe can be done");
    }

    close(fd[1]);
    close(fd[0]);
    waitpid(p1,NULL,0);
    waitpid(p2,NULL,0);
}
else
{
    printf("An inadequate number of arguments in the command prompt");
}   
}