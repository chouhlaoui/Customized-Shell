#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int p1, p2;
    char * argv[] = { "pwd", (char *) NULL };
    char * argv2[] = { "ls", "-l", "-n", (char *) NULL };
    p1 = fork();
	if (p1 < 0) {
		printf("\nCould not fork");
	}
    if (p1 == 0) {
        
		if (execvp(argv[0],argv) < 0) {
            p2 = fork();
            if (p2 == 0) 
            {
                if (execvp("ls", argv2) < 0) 
                {
			        printf("\nCould not execute command 2..");
    		    }
            }
            else 
            {
                wait(NULL);
	        }
        }
	} 
    while (wait(NULL)!= -1 || errno != ECHILD );
    


}