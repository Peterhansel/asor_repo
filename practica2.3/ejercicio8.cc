#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (int argc, char **argv){

	pid_t pid = fork();

	switch(pid){
		case -1:
			printf("Error al crear el proceso");
			return -1;
		case 0:{
			printf("Soy Hijo \n");
			pid_t sid = setsid();
			printf("HOLOO");
			if ((chdir("/tmp")) == -1) {
                                perror("No se pudo cambiar el directorio de trabajo");
                                exit(-1);
                        }
			int in = open("/dev/null", O_RDONLY, 0777);
			int out = open("/tmp/daemon.out",O_CREAT | O_WRONLY,0777);
			int err = open("/tmp/daemon.err", O_CREAT | O_WRONLY,0777);
			printf("%i %i %i",in,out,err);
			if(in==-1 || err==-1 || out==-1){
				printf("No se abrieron los ficheros");
				printf(strerror(errno));
				close(in);
				close(out);
				close(err);
			}
			dup2(out,1);
			dup2(err,2);
			dup2(in,0);
			execvp(argv[1],argv + 1);
			printf("El comando terminó de ejecutarse \n ");
			break;}
	
		default:
			printf("Soy Padre \n");
			//wait(0);//Cuando acaba el padre primero el ppid del hijo se vuelve 1
			break;
	}

	
	return 0;
}
