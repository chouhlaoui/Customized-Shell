
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
// delimiter avec  >, && , ; et espace 

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

int main(){
    char* ch[100];
    printf("%d",ParseSimple(strdup("ch ou d jd s"),ch," "));
}

// parse | et || a faire seule

