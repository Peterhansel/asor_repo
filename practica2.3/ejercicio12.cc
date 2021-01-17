#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static int countera=0;
static int counterb=0;

void handler(int signal){
	if(signal==SIGINT){
		countera++;
	}
	if(signal==SIGTSTP){
		counterb++;
	}

}

int main (int argc, char **argv){
	
	printf("%i \n",getpid());

	struct sigaction action;

	action.sa_handler = handler;
	action.sa_flags = SA_RESTART;

	sigaction(SIGINT,&action,NULL);
	sigaction(SIGTSTP, &action, NULL);

	while(countera+counterb<10){}
	
	printf("%i señales SIGINT fueron recibidas \n",countera);
	printf("%i señales SIGTSTP fueron recibidas \n", counterb);
	
	return 0;
}
