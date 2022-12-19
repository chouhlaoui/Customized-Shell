#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
void sigintHandler(__attribute__((unused)) int sig_num)
{
	signal(SIGINT, sigintHandler);
	printf("\n");
}

int main(void)
{
	int i, k;
	char* buf;


	while (1)
	{
		signal(SIGINT, sigintHandler);
		if (k == EOF)
		{
			exit(0);
		}
		
		i = fork();
		if (i == 0)
		{
			buf = readline("\n>>> ");
			if (strlen(buf) != 0) {
				add_history(buf);
			}
			if (strcmp(buf, "exit\n") == 0)
			{
					exit(0);
					break;
			}

		}
		else
			wait(&i);
	}
}