#include "file.h" 


int CheckPipe(char *line)
{
    int i=1;

    while ((line[i]!='\0'))
    {
        if ((line[i-1]!='|')&&(line[i]=='|'))
        {
            return 1;
        }
        i++;
    }

    if (line[i]=='\0')
    {
        return 0;
    }
}

int CheckRedirectFile(char *line)
{
    int i=1;

    while ((line[i]!='\0'))
    {
        if (line[i]=='>')
        {
            return 1;
        }
        i++;
    }

    if (line[i]=='\0')
    {
        return 0;
    }
}

int CheckNext(char *line)
{
    int i=0;

    while ((line[i]!='\0')&&(line[i]!=';'))
    {
        i++;
    }

    if (line[i]=='\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int CheckOr(char *line)
{
    int i=1;

    while ((line[i]!='\0'))
    {
        if ((line[i-1]=='|')&&(line[i]=='|'))
        {
            return 1;
        }
        i++;
    }

    if (line[i]=='\0')
    {
        return 0;
    }
}

int CheckAnd(char *line)
{
    int i=1;

    while ((line[i]!='\0'))
    {
        if ((line[i-1]=='&')&&(line[i]=='&'))
        {
            return 1;
        }
        i++;
    }
    
    if (line[i]=='\0')
    {
        return 0;
    }
}
