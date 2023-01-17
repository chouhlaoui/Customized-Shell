#include"file.h"

int ParseSimple(char* str, char** parsed,char* delim)
{
	int i=0;

    parsed[i] = strsep(&str, delim);
    while (parsed[i] != NULL)
    {
        if(strlen(parsed[i])==0)
        {
            i--;
        }
        i++;
        parsed[i] = strsep(&str, delim);
    }
    return i;
}


