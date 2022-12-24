#include"file.h"
int IsItFile(char* line)
{  
    if ((strstr(line, "bash") == NULL) && (strstr(line, "txt") == NULL))
    {
        return 0;
    } 
    else
    {
        return 1;
    }
}
