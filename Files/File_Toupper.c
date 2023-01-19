#include"file.h"

char * strtoupper( char *dest, const char * src ) {
    char * result = dest;

    for (int i = 0; src[i]!='\0'; i++) {
     
        if(src[i] >= 'a' && src[i] <= 'z') 
        {
            dest[i] = src[i] -32;
        }
        else if(src[i] >= 'A' && src[i] <= 'Z') 
        {
            dest[i] = src[i];
        }
    }
    
    return result;

}