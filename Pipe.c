#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int p1, p2;
    int fd[2];

    if (pipe(fd) < 0) 
    {
		printf("\nPipe could not be initialized");
	}

    char * argv[] = { "cat","t.bash", NULL };
    char * argv2[] = { "sort", NULL };
   
    p1 = fork();
    
	if (p1 < 0) {
		printf("\nCould not fork");
	}
    
    if (p1 == 0) 
    {
        dup2(fd[1],STDOUT_FILENO);
        close(fd[1]);
        close(fd[0]);

        if (execvp(argv[0], argv) < 0) 
        {
			printf("\nCould not execute command 1..");
            exit(1);
		}
        
	} 
    else{
        wait(NULL);
        p2=fork();
        if (p2 < 0) {
		    printf("\nCould not fork");
	    }

        if (p2 == 0) 
        {
            dup2(fd[0],STDIN_FILENO);
            close(fd[1]);
            close(fd[0]);

            if (execvp(argv2[0], argv2) < 0) 
            {
			    printf("\nCould not execute the piping command ..");
                exit(1);
		    }
	    } 
    }

    close(fd[1]);
    close(fd[0]);
    
}