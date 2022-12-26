#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int p1, p2;
    int fd[2];
    char * argv[] = { "pwd", (char *) NULL };
    char * argv2[] = { "ls","/Users/mac/Desktop/projet/", (char *) NULL };
    if (pipe(fd) < 0) {
		printf("\nPipe could not be initialized");
	}
    p1 = fork();
    
	if (p1 < 0) {
		printf("\nCould not fork");
	}
    
    if (p1 == 0) 
    {
        int x;
		
        if (execvp(argv2[0], argv2) < 0) {
			//printf("\nCould not execute command 1..");
            x=0;
            write(fd[1],&x,sizeof(x));
            close(fd[1]);
			exit(0);
		}
        
	} 
    else {
		wait(NULL);
		int y=1;
        close(fd[1]);
		if (read(fd[0],&y,sizeof(y))==-1)
		{
			y=1;
		}
		
		close(fd[0]);
		// Parent executing
        
        if(y == 1)
        {
		    p2 = fork();

		    if (p2 < 0) {
			    printf("\nCould not fork");
		    }
		
		    if (p2 == 0) {
			    if (execvp(argv[0], argv) < 0) {
				    printf("\nCould not execute command 2..");
				    exit(0);
			    }
		    } 
        }
        else
        {
            printf("Command 1 must be executed first");
        }
	}
    
}