#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
    int p1;
    char * argv[] = { "c","..", (char *) NULL };

    p1 = fork();
    
	if (p1 < 0) 
    {
		printf("\nCould not fork");
	}

    if (p1 == 0) 
    {
        int fd,file;
    
        fd = open("collection.txt",O_WRONLY | O_CREAT,0777);

        if (fd == -1)
        {
            return 2;
        }
    
        file = dup2(fd,STDOUT_FILENO);
        close(fd);
        
		if (execvp(argv[0],argv) < 0) {

			printf("\nCould not execute command 2..");
            exit(0);

        }
	} 
    while (wait(NULL)!= -1 || errno != ECHILD );


}