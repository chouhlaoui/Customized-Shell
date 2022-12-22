#include "file.h" 

/*Function to find out whether there's a pipe or not 
//cmd1 ; cmd2 ou bien cmd1 && cmd2 ou bien cmd1 || cmd2 */ 
int Composee(char* str)
{
    char* test;
    test = strsep(&str, ";");

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