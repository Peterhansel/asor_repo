#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv){
	
	//execvp(argv[1],argv + 1);
	system(argv[1]);

	printf("El comando terminó de ejecutarse \n ");
	return 0;

}

//con execvp no se imprime el mensaje porque el proceso se sustituye por el nuevo programa iniciado.
