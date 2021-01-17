#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
	
	if (argc <2){
		printf("No hay suficientes argumentos \n");
		return -1;
	}

	int file = open(argv[1], O_WRONLY);
	if(file==-1){
		printf("Error al crear pipe \n");
		return -1;
	}
	
	size_t len = strlen(argv[1]);
	ssize_t msg = write(file, argv[1],len);
	if(msg==-1){
		printf("Error al escribir \n");
		return -1;
	}
	close(file);
	
	return 0;
}
