#include"file.h"
//Execute cmd1&&cmd2
void ExecuteAndCommands(char** parsedArgs){
	int id = fork();
    if (id == 0) 
    {
		if (execvp(parsedArgs[0], parsedArgs) < 0) {
			printf("\nCould not execute command..");
		}
		exit(0);
	} 
    else 
    {
		// waiting for child to terminate
		wait(NULL);
	}
       
}  