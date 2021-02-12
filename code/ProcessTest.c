#include <sys/types.h> /* pid_t */
#include <sys/wait.h>  /* waitpid */
#include <stdio.h>     /* printf, perror */
#include <stdlib.h>    /* exit */
#include <unistd.h>    /* _exit, fork */

#define N 10

int main(void)
{
    pid_t pid;
    int status;
    char buff [20] = "./myexec";
    
    for (int i = 0; i < N; i++){
		pid = fork();
		if (pid == 0) {  
			execlp(buff, buff, NULL);
			exit(22);
		} 
	}
	for (int i = 0; i < N; i++){
		wait(&status);
		printf("Child Complete\n"); 
		status = WEXITSTATUS(status);
		if(status >= 0) printf("Father: son returned status %d\n",status);
	}	
  
    return 0;
}
