#include"file.h"
#define MAXCOM 1000 /* max number per line */ 
#define MAXLIST 100 /* max number of commands to be supported */ 

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
        if (IsItFile(inputString)==1)
        {
            FILE *fp=fopen(inputString,"r");
            DealWithFiles(fp);  
        }
        else
        {
            printf("not file");
        }
    }
    else
        break;
}
return 0;
}