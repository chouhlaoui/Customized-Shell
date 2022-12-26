/* Compiled : gcc -o Main -lreadline Main.c File_*.c */
/* Compiled : gcc -o Main Main.c File_*.c -lreadline*/ //windows

#include"file.h"

int main (void)
{
int NbCmd;
char inputString[MAXCOM], *parsedArgs[MAXLIST];

while (1)
{
    PrintDir();
	TakeInput(inputString);
    if(strcmp(inputString,"quit")!=0)
    {
        NbCmd=DelimiterAvecEspace(strdup(inputString),parsedArgs);
        if (PathHandler(parsedArgs)==0)
        {
            switch (Composee(inputString))
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
    else 
    {
        break;
    }
}
return 0;
}