#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() 
{
int pid_fils;
int status;
 pid_fils = fork();

 if (pid_fils == 0) { /* processus fils */
 char *binaryPath = "/bin/ls";
   
  execl(binaryPath, binaryPath, NULL);
exit(0); } 
else { /* processus père */
 printf("Pere : PID=%d, PPID=%d, PID fils=%d\n", getpid(),getppid(),pid_fils);
 printf("bye");
 wait(NULL);
 return 0;
 }
}
