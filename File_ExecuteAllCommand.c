#include"file.h"

void ExecuteAllCommand(char** parsedArgs,int N)
{

if(N==2)
{
	int p1, p2;

	char *CommandOne[LineLength] ;
    char *CommandTwo[LineLength];

	ParseSimple(strdup(parsedArgs[0]),CommandOne," ");
	ParseSimple(strdup(parsedArgs[1]),CommandTwo," ");

    int Detect1 = PathHandler(CommandOne);
    if(Detect1 == 1)
    {
        printf("");
    }

    else if(Detect1 == 0)
    {
        p1 = fork();

		if (p1 < 0) 
        {
	        printf("\nCould not fork\n");
        }

        if(p1 == 0)
        {
            if (execvp(CommandOne[0], CommandOne) < 0) 
            {
		        printf("\nCould not execute Command 1 !\n");
                exit(1);
		    }
        }

        else
        {
            waitpid(p1,NULL,0);
        }
    }

    else
    {
        printf("\nCould not execute Command 1 !\n");
    }


    int Detect2 = PathHandler(CommandTwo);
    if(Detect2 == 1)
    {
        printf("");
    }

    else if(Detect2 == 0)
    {
        p2 = fork();

		if (p2 < 0) 
        {
	        printf("\nCould not fork\n");
        }

        if(p2 == 0)
        {
            if (execvp(CommandTwo[0], CommandTwo) < 0) 
            {
		        printf("\nCould not execute Command 2 !\n");
                exit(1);
		    }
        }

        else
        {
            waitpid(p2,NULL,0);
        }
    }

    else
    {
        printf("\nCould not execute Command 2 !\n");
    }
    
    
}

else
{
    printf("An inadequate number of arguments in the command prompt\n");
}

}