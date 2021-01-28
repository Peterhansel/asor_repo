#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

int main (int argc , char **argv){
	
	struct addrinfo hints, *res;
	fd_set fds;
	char bufferH[NI_MAXHOST], bufferS[NI_MAXSERV];
        struct sockaddr_storage client;
        socklen_t clientlen = sizeof(client);
        char buf[200];
	int client_sd;

	if(argc<3){
		printf("No hay suficientes argumentos \n");
		return -1;
	}
	
	memset(&hints,0,sizeof(hints));
	
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family= AF_UNSPEC;
	hints.ai_socktype =SOCK_STREAM;
	
	int e = getaddrinfo(argv[1],argv[2], &hints, &res);
	if (e != 0){
		printf("Ha habido un problema en getaddrinfo \n");
		return -1;
	}
	
	int sd = socket(res->ai_family,res->ai_socktype,0);
	
	if(sd==-1){
		printf("Hubo un error al crear el socket \n");
		return -1;
	}
	
	e = bind(sd,res->ai_addr,res->ai_addrlen);
	
	if(e!=0){
		printf("Hubo un problema al asignar la direccion \n");
		return -1;
	}
	int rc=listen(sd,20);
	while(1){
		if((client_sd= accept(sd,(struct sockaddr *)&client,&clientlen))==-1){
			printf("Error al aceptar conexion cliente \n");
			return 0;
		}
		if(fork()==0){
			close(sd);
			e = getnameinfo((struct sockaddr *)&client,clientlen, bufferH, NI_MAXHOST, bufferS, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
			if(e!=0){
				printf("Error al conseguir el nombre de la dir \n");
				return -1;
			}
		
			printf("Conexion de %s:%s \n",bufferH,bufferS);
			int bytes;
			while(bytes=recv(client_sd,buf,200,0)){
				if(bytes==-1){
					printf("Error al recibir datos de cliente \n");
				}
				else{
					buf[bytes]='\0';
					if((send(client_sd,buf,bytes,0))==-1){
						printf("Error al enviar datos a cliente \n");
					}
				}
			}
			if((close(client_sd))==-1){
				printf("Error al cerrar el socket cliente \n");
			}
			printf("Conexion desde %s %s terminada \n",bufferH,bufferS);
			return 0;
		}
		close(client_sd);
	}
	return 0;
}
