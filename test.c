#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>

void DealWithSpace(char * line,char * argv[])
{ 
    int i=-1;
    char*  espace = strstr(line, " ");
    if (espace)
    {
        char * token = strtok(line, " ");
        while( token != NULL ) 
        {
            i++;
            strcpy(argv[i],token);
            printf( " %s\n", token ); 
            token = strtok(NULL, " ");
        }
    }
}

int main()
{
	int i;
	char* buf;
	char ** arg;

	while (1)
	{
		i = fork();
		if (i == 0)
		{
			buf = readline("\n>>> ");
			
			if (strlen(buf) != 0) {
				add_history(buf);
			}
			
			
		}
		else{
				wait(&i);
			}
			

	}
}