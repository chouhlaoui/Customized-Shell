#include"file.h"

// Exexute Help and cd
int PathHandler(char** parsed)
{
	if (strcmp(parsed[0], "cd") == 0) 
    {
		if (chdir(parsed[1])==-1)
		{
			return -1;
		}
		return 1;
	}
    else if (strcmp(parsed[0], "help") == 0) 
    {
		openHelp();
		return 1;
	}
    else{
        return 0;
	}
	
}
