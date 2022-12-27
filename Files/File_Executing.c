#include"file.h"
void Executing(char* line)
{
    int NbCmd;
    char *parsedArgs[LineLength];
    char* h;


    
        if(verifnext(line) == 0)
        {
            if(verifor(line) == 0)
            {
                if(verifand(line) == 0)
                {
                    
                    if (PathHandler(parsedArgs)==0)
                    {
                        NbCmd=ParseSimple(strdup(line),parsedArgs," ");
                        ExecuteOneCommand(parsedArgs);
                    }
                    else if (PathHandler(parsedArgs)==-1)
                    {
                        printf("wrong path");
                    }
                }
                else
                {
                    NbCmd=ParseSimple(strdup(line),parsedArgs,"&&");
                    ExecuteAndCommands(parsedArgs);
                }
            }   
            else
            {
            printf("||");
            }
        }
        else
        {
            printf(";");
        }           
    
}