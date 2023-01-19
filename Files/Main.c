
#include"file.h"

int main (void)
{

char inputString[LineLength];
char result[LineLength];

while (1)
{  
    PrintDir();
    if (TakeInput(inputString)){
        continue;
    }

    if(strcmp(strtoupper(result, inputString),"QUIT")!=0)
    {
        if(strcmp(strtoupper(result, inputString),"HISTORY")!=0)
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
        {
            ShowHistory();
        }
    }
    else
    {
        break;
    }
}
}