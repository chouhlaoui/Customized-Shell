#include"file.h"

void ExecuteAllCommand(char** parsedArgs,int N){

if(N==2)
{
	int p1, p2;

	char *CommandOne[LineLength] ;
    char *CommandTwo[LineLength];

	ParseSimple(strdup(parsedArgs[0]),CommandOne," ");
	ParseSimple(strdup(parsedArgs[1]),CommandTwo," ");
	
    p1 = fork();

	if (p1 < 0) 
	{
		printf("\nCould not fork");
	}

    if (p1 == 0) 
	{
		if (execvp(CommandOne[0],CommandOne) < 0) 
		{
            printf("\nCould not execute command 1..");
            exit(1);
        }
	} 
	
	else
	{
		wait(NULL);
		p2 = fork();
            if (p2 == 0) 
            {
                if (execvp(CommandTwo[0],CommandTwo) < 0) 
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
else{
	printf("An inadequate number of arguments in the command prompt");
}

}

