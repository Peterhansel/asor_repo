#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
	struct utsname buffer;
	if(uname(&buffer)==-1){
		perror("Error: ");
		return -1;
	}
	else{
		printf("SysName: %s \n",buffer.sysname);
                printf("NodeName: %s \n",buffer.nodename);
                printf("Release: %s \n",buffer.release);
                printf("Version: %s \n",buffer.version);
                printf("Machine: %s \n",buffer.machine);
	}
	return 0;
}
