#include"file.h"
#define MAXCOM 1000 /* max number per line */ 

int main (void)
{
int NbCmd;
char inputString[MAXCOM];

while (1)
{  
    PrintDir();
	TakeInput(inputString);
    if(strcmp(inputString,"quit")!=0)
    {
        if (IsItFile(inputString)==1)
        {
            FILE *fp=fopen(inputString,"r");
            if (fp==NULL)
            {
                printf("File Not Found ");
            }
            else
            {
                DealWithFiles(fp);                  
            }
        }
        else
        {
            Executing(inputString);
        }
    }
    else
        break;
}
return 0;
}