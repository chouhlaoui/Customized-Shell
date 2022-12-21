#include"file.h"


void PrintDir()
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}


void DealWithFiles(FILE *fp)
{
    char ligne[80];

    while(!feof(fp))
    {
        fgets(ligne, 80, fp);
        if (strcmp(ligne, "exit\n") == 0)
        {
            break;
        }
        printf("%s", ligne);
        //executer(ligne);
        
    }
    
    printf("\nFINISHED\n");
    fclose(fp);
}
  
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

/*Function to take input*/ 
int TakeInput(char* str)
{
	char* buf;

	buf = readline("\n>>> ");
	if (strlen(buf) != 0) {
		add_history(buf);
		strcpy(str, buf);
		return 0;
	} else {
		return 1;
	}
    
}

/*Function to find out whether there's a pipe or not */ 
//cmd1 ; cmd2 ou bien cmd1 && cmd2 ou bien cmd1 || cmd2
int Composee(char* str)
{
	char* buf;

	buf = readline("\n>>> ");
	if (strlen(buf) != 0) 
    {
		add_history(buf);
		strcpy(str, buf);
	} 
    
}