#include"file.h"

int TakeInput(char* str)
{
	char* buf;

	buf = readline("% ");

	if (strlen(buf) != 0) 
	{
		add_history(buf);
		strcpy(str, buf);
		FILE *fp=fopen("/Users/mac/Desktop/projet/Interpreteur-De-Commande-Shell/Files/History.txt","a+");
       
	    if (fp==NULL)
        {
            printf("File Not Found");
        }
		
		fputs("\n", fp) ;
		fputs(buf,fp);	
		fclose(fp);

		return 0;
	} 
	
	else{
		return 1;
	}
}