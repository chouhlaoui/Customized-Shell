#include"file.h"

void ExecuteAndCommands(char** parsedArgs,int N)
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

    
    int Detect1 = PathHandler(CommandOne);
    if(Detect1 == 1)
    {
            
        int Detect2 = PathHandler(CommandTwo);

        if (Detect2 == 1)
        {
            printf("");
        }

        else if(Detect2 == 0)
        {
            p1 = fork();

		    if (p1 < 0) 
            {
			    printf("\nCould not fork");
	        }

            if(p1 == 0)
            {
                if (execvp(CommandTwo[0], CommandTwo) < 0) 
                {
				    printf("\nCould not execute command 2..");
                    exit(1);
			    }
            }

            else
            {
                wait(NULL);
            }
        }

        else
                {
                    printf("\nCould not Execute Second Command");
                }
    
    }

    else if(Detect1 == 0)
    {
        p1 = fork();

		if (p1 < 0) 
        {
	        printf("\nCould not fork");
        }

        if(p1 == 0)
        {
            int CommandState;

            if (execvp(CommandOne[0], CommandOne) < 0) 
            {
		        CommandState = 0;
                write(fd[1],&CommandState,sizeof(CommandState));
                close(fd[1]);
			    exit(1);
		    }
        }

        else
        {
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
                int Detect2 = PathHandler(CommandTwo);

                    if (Detect2 == 1)
                    {
                        printf("");
                    }

                    else if(Detect2 == 0)
                    {
                        p2 = fork();

		                if (p2 < 0) 
                        {
			                printf("\nCould not fork");
		                }

                        if(p2 == 0)
                        {
                            if (execvp(CommandTwo[0], CommandTwo) < 0) 
                            {
				                printf("\nCould not execute command 2..");
                                exit(1);
			                }
                        }
                        else
                        {
                            wait(NULL);
                        }
                    }     
            }
            
            else
            {
                printf("\nCommand 1 must be executed first !");
            }
        }
    }

    else
    {
        printf("\nCommand 1 must be executed first !");
    }
    
}

else
{
    printf("An inadequate number of arguments in the command prompt");
}

}