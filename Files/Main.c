/* Compiled : gcc -o Main -lreadline Main.c File_*.c */
/* Compiled : gcc -o Main Main.c File_*.c -lreadline*/ //windows
#include"file.h"

int main (void)
{

char inputString[LineLength];

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