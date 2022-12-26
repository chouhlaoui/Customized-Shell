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
    char * argv2[] = { "jk","/Users/mac/Desktop/projet/", (char *) NULL };
    if (pipe(fd) < 0) {
		printf("\nPipe could not be initialized");
	}
    p1 = fork();
    
	if (p1 < 0) {
		printf("\nCould not fork");
	}
    
    if (p1 == 0) 
    {
        int x=1;
        close(fd[0]);
		write(fd[1],&x,sizeof(x));
        if (execvp(argv2[0], argv2) < 0) {
			printf("\nCould not execute command 1..");
            x=0;
            write(fd[1],&x,sizeof(x));
            close(fd[1]);
            printf("x = %d ",x);
			exit(0);

		}
        
	} 
    else {
        int y=0;
        close(fd[1]);
		read(fd[0],&y,sizeof(y));
		close(fd[0]);
		// Parent executing
        printf("y = %d",y);
        if(y==1)
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
		    } else {
			// parent executing, waiting for two children
			    wait(NULL);
			    wait(NULL);
		    }
        }
        else
        {
            printf("sakarna");
        }
	}
    
}