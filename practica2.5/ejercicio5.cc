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
	if(argc<3){
		printf("No hay suficientes argumentos \n");
		return -1;
	}
	
	memset(&hints,0,sizeof(hints));
	
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family= AF_UNSPEC;
	hints.ai_socktype =SOCK_DGRAM;
	
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
	
	freeaddrinfo(res);
	
	int i = 0;
	pid_t process[10];
	for(i;i<10;i++){
		pid_t pid= fork();
		process[i]=pid;
		switch(pid){
			case -1:
				printf("Error al crear el proceso \n");
				break;
			case 0:{
				while(1){
		
					char bufferH[NI_MAXHOST], bufferS[NI_MAXSERV];
					struct sockaddr_storage client;
					socklen_t clientlen = sizeof(client);
					char buf[200];
					char timee[64];
		
					int c = recvfrom(sd, buf, 100, 0,(struct sockaddr *)&client,&clientlen);
	
					buf[c]='\0';
		
					e = getnameinfo((struct sockaddr *)&client,clientlen, bufferH, NI_MAXHOST, bufferS, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
					if(e!=0){
						printf("Error al conseguir el nombre de la dir \n");
						return -1;
					}	
		
					printf("Mensaje de %s:%s \n",bufferH,bufferS);

					time_t tim;
					struct tm *t;
					int tlen;
					time(&tim);
					t = localtime(&tim);

					switch(buf[0]){
						case 't':
							tlen =strftime(timee,64, "%H:%M",t);
							sendto(sd,timee,tlen,0,(struct sockaddr *)&client,clientlen);
							break;
						case 'd':
							tlen= strftime(timee,64, "%d de %B de %Y",t);
							sendto(sd,timee,tlen,0,(struct sockaddr *)&client,clientlen);
							break;
						case 'q':
							printf("PROC CERRADO \n");
							return 0;
						default:
							printf("Comando desconocido \n");
					}
		
				}
				default:
					for(int o=0;o<10;o++){
						printf("%i\n",process[o]);
						wait(process[o]);
					}
					break;
				}
			}
		}
	close(sd);
	return 0;
}
