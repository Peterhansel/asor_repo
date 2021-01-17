#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv){
	
	execve(argv[1],argv + 1);

	printf("El comando terminó de ejecutarse \n ");
	return 0;

}
