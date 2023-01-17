#include"file.h"
int IsItFile(char* line)
{  
    if ((strstr(line, "bash") == NULL) && (strstr(line, "txt") == NULL))
    {
        return 0;
    } 
    else
    {
        if ((strstr(line, ">") == NULL) && (strstr(line, ";") == NULL)&&(strstr(line, "&&") == NULL) && (strstr(line, "|") == NULL)){
            return 1;
        }
        return 0;
    }
}
