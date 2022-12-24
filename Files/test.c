#include"file.h"

int main (void)
{
    char *string,*found;

    string = strdup("Chourouk || dcgd ");

    found = strsep(&string,";");
printf("%s",found);

    if(strsep(&string,";") == NULL)
    {
        if(strsep(&string,"||") == NULL)
        {
            if(strsep(&string,"&&") == NULL)
            {
                printf("0");
            }
            else
            {
                printf("3");
            }
        }
        else
        {
                printf("2");
        }
        
    }
    else
    {
                printf("1");
    }
}
    