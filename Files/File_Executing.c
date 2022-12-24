#include"file.h"

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