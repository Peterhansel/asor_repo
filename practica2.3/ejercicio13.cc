#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

static int conservar=0;

void handler(int signal){
	
	if(signal==SIGUSR1) conservar=1;
	
}


int main(int argc, char **argv){

	struct sigaction action;

	action.sa_handler=handler;
	action.sa_flags=SA_RESTART;
	
	sigaction(SIGUSR1,&action,NULL);
	
	printf("%i \n",getpid());
	printf("El programa se borara en %s segundos \n",argv[1]);
	
	fflush(stdout);
	sleep(atoi(argv[1]));

	if(!conservar){

	unlink(argv[0]);
	printf("El ejecutable fue borrado \n");
	}
	else{printf("El ejecutable se salvo \n");}
	
	return 0;
}
