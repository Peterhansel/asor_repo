//NO ME FUNCIONA EL READ DE HIJO
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv){

	int p_h[2];
	int h_p[2];

	if(pipe(p_h)==-1 || pipe(h_p)==-1){
		printf("Hubo un error al crear la tuberia");
		return -1;
	}

	pid_t pid = fork();
	int count=0;
	switch(pid){

		case -1:
			printf("Error al crear el proceso");
			break;
		case 0: //HIJO
			close(p_h[1]);
			close(h_p[0]);
			char msg[256];
			char hijo[1];
			hijo[0]='1';
			for(count;count<10;count++){
				ssize_t tam = read(p_h[0],msg,256);
				if(tam=-1){
					printf("Error al leer de p_h");
					return -1;
				}
				msg[tam]='\0';
				printf("Mensaje de Padre recibido %s \n",msg);
				if(count==9)hijo[0]='q';
				if(write(h_p[1],hijo,1)==-1){
					printf("Error al escribir en h_p \n");
					return -1;
				}
			}
			close(h_p[1]);
			close(p_h[0]);
			break;
		default: //PADRE
			char terminal[256];
			char padre[1]={'1'};
			close(h_p[1]);
			close(p_h[0]);
			while(padre[0]!='q'){
				ssize_t tam = read(0,terminal,256);
				if(tam==-1){
					printf("Error al leer del terminal");
					return -1;
				}
				terminal[tam+1]='\0';
				tam=write(p_h[1],terminal,tam+1);
				if(tam==-1){
                                        printf("P: Error al escribir en la tuberia \n");
                                        return -1;
                                }
				padre[0]='0';
				while(padre[0]!='1' && padre[0]!='q'){
					tam =read(h_p[0],&hijo,1);
					if(tam==-1){
						printf("Error al leer de h_p");
						return -1;
					}
				}
			}
			close(p_h[1]);
			close(h_p[0]);
		break;
	}
	return 0;
}
