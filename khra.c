#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
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
			printf("\nCould not execute command 1..");
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
    else 
    {
        wait(NULL);
	}


}

void execArgsPiped(char** parsed, char** parsedpipe)
{
	// 0 is read end, 1 is write end
	int pipefd[2];
	int p1, p2;

	if (pipe(pipefd) < 0) {
		printf("\nPipe could not be initialized");
		return;
	}
	p1 = fork();
	if (p1 < 0) {
		printf("\nCould not fork");
		return;
	}

	if (p1 == 0) {
		// Child 1 executing..
		// It only needs to write at the write end
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		if (execvp(parsed[0], parsed) < 0) {
			printf("\nCould not execute command 1..");
			exit(0);
		}
	} else {
		// Parent executing
		p2 = fork();

		if (p2 < 0) {
			printf("\nCould not fork");
			return;
		}

		// Child 2 executing..
		// It only needs to read at the read end
		if (p2 == 0) {
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0) {
				printf("\nCould not execute command 2..");
				exit(0);
			}
		} else {
			// parent executing, waiting for two children
			wait(NULL);
			wait(NULL);
		}
	}
}

int parsePipe(char* str, char** strpiped)
{
	int i;
	for (i = 0; i < 2; i++) {
		strpiped[i] = strsep(&str, "|");
		if (strpiped[i] == NULL)
			break;
	}

	if (strpiped[1] == NULL)
		return 0; // returns zero if no pipe is found.
	else {
		return 1;
	}
}



