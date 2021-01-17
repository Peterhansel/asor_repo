#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (int argc, char **argv){

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
