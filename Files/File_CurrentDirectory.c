#include"file.h"

void PrintDir(void)
{
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\n[ %s ]", cwd);
}