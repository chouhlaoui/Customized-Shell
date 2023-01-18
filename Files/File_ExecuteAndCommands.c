#include"file.h"

void ExecuteAndCommands(char** parsedArgs,int N){

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
		if (strcmp(CommandOne[0],"cd")==0)
        {
            if (PathHandler(CommandOne)==-1)
            {
                CommandState = 0;
                write(fd[1],&CommandState,sizeof(CommandState));
                close(fd[1]);
			    exit(1);
            }
        }

        else if (strcmp(CommandOne[0],"help")==0)
        {
            PathHandler(CommandOne);
			exit(0); 
        }

        else
        {
            if (execvp(CommandOne[0], CommandOne) < 0) 
            {
            CommandState = 0;
            write(fd[1],&CommandState,sizeof(CommandState));
            close(fd[1]);
			exit(1);
		    }
        }
        
	} 
    else {
		wait(NULL);

		int ReceivedState = 1;
        close(fd[1]);

		if (read(fd[0],&ReceivedState,sizeof(ReceivedState))==-1)
		{
			ReceivedState=1;
		}

		close(fd[0]);
        
        if(ReceivedState == 1)
        {
            p2 = fork();

		    if (p2 < 0) 
            {
			    printf("\nCould not fork");
		    }
		
		    if (p2 == 0) 
            {
                if (strcmp(CommandOne[0],"cd")==0)
                {
                    chdir(CommandOne[1]); 
                    char ch[100];
                    getcwd(ch,100);
                    printf("Current Path : %s \n",ch);
                }
                
                if (strcmp(CommandTwo[0],"cd")==0)
                {
                    if (PathHandler(CommandTwo)==-1)
                    {   
                        printf("\nCould not execute command 2");
                    }

                    char ch[100];
                    getcwd(ch,100);
                    printf("Updated Path : %s \n",ch);
                }

                else if (strcmp(CommandTwo[0],"help")==0)
                {
                    PathHandler(CommandTwo); 
                }

                else
                {
                    if (execvp(CommandTwo[0], CommandTwo) < 0) 
                    {
				        printf("\nCould not execute command 2..");
			        }
		        }
            }
			   
            wait(NULL);

        }
        
        else
        {
            printf("Command 1 must be executed first");
        }
	}

}  
else{
    printf("An inadequate number of arguments in the command prompt");
}

}