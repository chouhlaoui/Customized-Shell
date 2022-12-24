#include"file.h"
#define MAXCOM 1000 /* max number per line */ 
#define MAXLIST 100 /* max number of commands to be supported */ 

void PrintDir(void)
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\n[%s]", cwd);
}

/*Function to take input*/ 
void TakeInput(char* str)
{
	char* buf;

	buf = readline("% ");
	if (strlen(buf) != 0) {
		add_history(buf);
		strcpy(str, buf);
	} 
}

/*Function to find out whether there's a pipe or not 
//cmd1 ; cmd2 ou bien cmd1 && cmd2 ou bien cmd1 || cmd2 */ 


int DelimiterAvecEspace(char* str, char** parsed)
{
	int i=0;
    parsed[i] = strsep(&str, " ");
    while (parsed[i] != NULL)
    {
       i++;
       parsed[i] = strsep(&str, " ");
    }
    return i;
}

// Exexute Help and cd
int PathHandler(char** parsed)
{
	if (strcmp(parsed[0], "cd") == 0) 
    {
		chdir(parsed[1]);
		return 1;
	}
    else if (strcmp(parsed[0], "help") == 0) 
    {
		openHelp();
		return 1;
	}
    else{
        return 0;
	}
}

void openHelp(void)
{
	puts("\n***WELCOME TO OUR SEA PROJECT***"
		"\nProject Developed by Chourouk Lahlaoui and Yahya Chebbi"
		"\nWith this Shell you can:"
		"\nUse cd and all other general commands available in UNIX shell"
        "\nUse composed Commands << cmd1 ; cmd2 >> ou bien << cmd1 && cmd2 >> ou bien << cmd1 || cmd2 >>"
        "\nCheck your history and trace your command lines"
		"\nHave pipe Handeling"
        "\nAnd finally you can exit whenever you want using << quit >>");
}

//Execute cmd
void ExecuteOneCommand(char** parsedArgs){
	int id = fork();
    if (id == 0) 
    {
		if (execvp(parsedArgs[0], parsedArgs) < 0) 
        {
			printf("\nCould not execute command..");
		}
		exit(0);
	} 
    else 
    {
		wait(NULL);
	}
       
}  
	
//Execute cmd1;cmd2
void ExecuteAllCommand(char** parsedArgs){
	int id = fork();
    if (id == 0) 
    {
		if (execvp(parsedArgs[0], parsedArgs) < 0) 
        {
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

//Execute cmd1&&cmd2
void ExecuteAndCommands(char** parsedArgs){
	int id = fork();
    if (id == 0) 
    {
		if (execvp(parsedArgs[0], parsedArgs) < 0) 
        {
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

//Execute cmd1||cmd2
void ExecuteOrCommands(char** parsedArgs){
	int id = fork();
    if (id == 0) 
    {
		if (execvp(parsedArgs[0], parsedArgs) < 0) 
        {
			printf("\nCould not execute command..");
		}
		exit(0);
	} 
    else 
    {
		wait(NULL);
	}
       
}  


/*
1 -> File
0 -> Not a File
*/
int IsItFile(char* line)
{  
    if ((strstr(line, "bash") == NULL) && (strstr(line, "txt") == NULL))
    {
        return 0;
    } 
    else
    {
        return 1;
    }
}

void DealWithFiles(FILE *fp)
{
    char ligne[MAXLIST];
    while(!feof(fp))
    {
        fgets(ligne, 80, fp);
        ligne[strlen(ligne)-1] = '\0';
        if (strcmp(ligne, "quit") == 0)
        {
            break;
        }
        sleep(2);
       // printf("%s", ligne);
        Executing(ligne);
        printf("\n_______________________________________\n");
        
    }
    fclose(fp);
}

void Executing(char* line)
{
    int NbCmd;
    char *parsedArgs[MAXLIST];

    NbCmd=DelimiterAvecEspace(strdup(line),parsedArgs);
    
    if (PathHandler(parsedArgs)==0)
    {
        switch (Composee(line))
        {
        case 1:
            printf(";");
            break;
        case 2:
            printf("||");
            break;  
        case 3:
            printf("&&");
            break;
        default:
            ExecuteOneCommand(parsedArgs);
 	        //fprintf(stderr, "Erreur %d\n", errno);
            break;
            }
        }
}

int Composee(char* str)
{

    if(strsep(&str, ";") == NULL)
    {
        if(strsep(&str, "||") == NULL)
        {
            if(strsep(&str, "&&") == NULL)
            {
                return 0;
            }
            else
            {
                return 3;
            }
        }
        else
        {
            return 2;
        }
        
    }
    else
    {
        return 1;
    }
    
}