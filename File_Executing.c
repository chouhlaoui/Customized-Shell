#include"file.h"

void Executing(char* line)
{
    int NbCmd;
    char *parsedArgs[LineLength];
 

    if(CheckNext(line) == 0)
    {
        if(CheckOr(line) == 0)
        {
            if(CheckAnd(line) == 0)
            {                    
                if(CheckPipe(line) == 0)
                {
                    if(CheckRedirectFile(line) == 0)
                    {
                        NbCmd =ParseSimple(strdup(line),parsedArgs," ");
                        int DetectPathHandler = PathHandler(parsedArgs);
                        if (DetectPathHandler==0) 
                        {   
                            ExecuteOneCommand(parsedArgs);
                        }
                        else if (DetectPathHandler == -1)
                        {
                            printf("Wrong Path\n");
                        }
                    }

                    else
                    {
                        NbCmd=ParseSimple(strdup(line),parsedArgs,">");
                        ExecuteRedirected(parsedArgs,NbCmd);
                    }
                }

                else
                {
                    NbCmd=ParseSimple(strdup(line),parsedArgs,"|");
                    ExecutePiped(parsedArgs,NbCmd);
                }
            }

            else
            {
                NbCmd=ParseSimple(strdup(line),parsedArgs,"&&");
                ExecuteAndCommands(parsedArgs,NbCmd);
            }
        }  
         
        else
        {
            NbCmd=ParseSimple(strdup(line),parsedArgs,"||");
            ExecuteOrCommands(parsedArgs,NbCmd);
        }
    }

    else
    {
        NbCmd=ParseSimple(strdup(line),parsedArgs,";");
        ExecuteAllCommand(parsedArgs,NbCmd);
    }           
    
}