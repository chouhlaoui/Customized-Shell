#include "file.h" 


int verifpipe(char *line)
{
return 0;
}

int verifredirectfile(char *line)
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

int verifnext(char *line)
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

int verifor(char *line)
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

int verifand(char *line)
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
