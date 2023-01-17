#include"file.h"

void PrintDir(void)
{
	char Path[1024];
	getcwd(Path, sizeof(Path));
	printf("\n[ %s ]", Path);
}