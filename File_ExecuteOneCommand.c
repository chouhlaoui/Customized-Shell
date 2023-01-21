#include "file.h"

void ExecuteOneCommand(char** parsedArgs){
	
	int id = fork();
    if (id == 0) 
    {
		if (execvp(parsedArgs[0], parsedArgs) < 0) 
		{
			printf("\nCould not execute command..\n");
		}
	} 

    else 
    {
		waitpid(id,NULL,0);
	}
       
}  