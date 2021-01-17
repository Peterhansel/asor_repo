#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char **argv){

	if(argc < 5){
		printf("Revisa el formato del comando");
		return -1;
	}

	int tuberia[2];
	if(pipe(tuberia)==-1){
		printf("Hubo un error al crear la tuberia");
		return -1;
	}

	pid_t pid = fork();
	int fileD;

	switch(pid){

		case -1:
			printf("Error al crear el proceso");
			break;
		case 0: //HIJO
			close(tuberia[1]);
			fileD=dup2(tuberia[0],0);
			close(tuberia[0]);
			execlp(argv[3],argv[3],argv[4],NULL);
			break;
		default: //PADRE
			close(tuberia[0]);
			fileD=dup2(tuberia[1],1);
			close(tuberia[1]);
			execlp(argv[1],argv[1],argv[2],NULL);
			break;
	}
}
