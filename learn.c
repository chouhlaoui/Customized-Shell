#include <stdio.h>
#include <string.h>
//decouper une chaine contenant une redirection, pipe, ;
/*void supprime(char *texte, char* x, char** parsed)   
{
    int p ,i;
    for(i=0;texte[i] != '\0';i++)
    {
        if (texte[i] == x)  // on a trouve
        {
            for(p=i; texte[p]!=0; p++)
            texte[p]=texte[p+1];
        }
    }
}*/
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

int main(void)
{
    
    char *parsed[1000];
    char *delim="||";
    int s=ParseSimple(strdup("ch | dh;db sdcj;ef"),parsed,delim);
    
       printf("%d : %s",s,parsed[0]);
    
    
}
