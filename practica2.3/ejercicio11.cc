#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
	
	setenv("SLEEP_SECS","12",0);	
	sigset_t blk;
	sigemptyset(&blk);
	sigaddset(&blk, SIGINT);
	sigaddset(&blk, SIGTSTP);
	
	printf("%i \n",getpid());
	char *slp = getenv("SLEEP_SECS");
	int time;
	time  = atoi(slp);
	fflush(stdout);
	sigprocmask(SIG_BLOCK,&blk,NULL);

	sleep(time);
	
	sigset_t pending;
	sigpending(&pending);
	
	if(sigismember(&pending,SIGINT)==1){
		printf("SIGINT recibido \n");
	}
	
	if(sigismember(&pending,SIGTSTP)==1){
                printf("SIGTSTP recibido \n");
        }
	
	sigprocmask(SIG_UNBLOCK,&blk,NULL);

	printf("Programa termina \n");
	
	return 0;
}
