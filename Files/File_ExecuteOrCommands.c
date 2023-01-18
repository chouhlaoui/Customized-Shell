#include"file.h"
void ExecuteOrCommands(char** parsedArgs,int N){

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

	if (p1 < 0) 
    {
		printf("\nCould not fork");
	}
    
    if (p1 == 0) 
    {
        int CommandState;
        
        close(fd[0]);
        int DetectPathHandler = PathHandler(CommandOne);
        if (DetectPathHandler==0) 
        {   
            if (execvp(CommandOne[0], CommandOne) < 0) 
            {
			    CommandState = 0;
                write(fd[1],&CommandState,sizeof(CommandState));
                close(fd[1]);
			    exit(1);
		    }
        }
        else if (DetectPathHandler == -1)
        {
            CommandState = 0;
            write(fd[1],&CommandState,sizeof(CommandState));
            close(fd[1]);
		    exit(1);
        }
        else{
            CommandState = 1;
            write(fd[1],&CommandState,sizeof(CommandState));
            close(fd[1]);
		    exit(0);
        }
		
        
	} 
    else {
		wait(NULL);

        if (strcmp(CommandOne[0],"cd")==0)
        {
            chdir(CommandOne[1]); 
            char ch[100];
            getcwd(ch,100);
        }
        
		int ReceivedState = 1;
        close(fd[1]);

		if (read(fd[0],&ReceivedState,sizeof(ReceivedState))==-1)
		{
			ReceivedState=1;
		}

		close(fd[0]);
        
        if(ReceivedState == 0)
        {
            p2 = fork();

		    if (p2 < 0) 
            {
			    printf("\nCould not fork");
		    }
		
		    if (p2 == 0) 
            {
                int DetectPathHandler = PathHandler(CommandTwo);
                if (DetectPathHandler==0) 
                {   
                    if (execvp(CommandTwo[0], CommandTwo) < 0) 
                    {
				        printf("\nCould not execute any command ..");
			        }
                }
                else if (DetectPathHandler == -1)
                {
                    printf("Wrong Path");
                }
                
            }
			   
            wait(NULL);

        }
        
        
        
	}

}  
else{
    printf("An inadequate number of arguments in the command prompt");
}

}