#include"file.h"
/*Function to take input*/ 
void TakeInput(char* str)
{
	char* buf;

	buf = readline("% ");
	if (strlen(buf) != 0) {
		add_history(buf);
		strcpy(str, buf);
	} 
}