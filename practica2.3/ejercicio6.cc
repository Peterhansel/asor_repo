#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>



int Info(){

	pid_t pid = getpid();
	pid_t ppid = getppid();
	pid_t pgid = getpgid(pid);
	pid_t sid = getsid(pid);
	
	struct rlimit rlim;
	getrlimit(RLIMIT_NOFILE, &rlim);

	char ruta[2048];
	getcwd(ruta,sizeof(ruta));

	printf("PID: %i PPID: %i PGID: %i SID: %i ",pid,ppid,pgid,sid);
	printf("Limite de ficheros: %lli",(long long int) rlim.rlim_max);
	printf("\n");
	printf(ruta);
	printf("\n");

	return 0;
}

int main (int argc, char **argv){

	pid_t pid = fork();
	pid_t sid;

	switch(pid){
		case -1:
			printf("Error al crear el proceso");
			return -1;
		case 0:
			printf("Soy Hijo \n");
			sid = setsid();
			if ((chdir("/tmp")) == -1) {
                                perror("No se pudo cambiar el directorio de trabajo");
                                exit(-1);
                        }
			Info();
			break;
		default:
			printf("Soy Padre \n");
			Info();
			wait(0);//Cuando acaba el padre primero el ppid del hijo se vuelve 1
			break;
	}

	
	return 0;
}
