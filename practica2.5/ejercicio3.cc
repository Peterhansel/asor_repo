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

        if(argc<4){
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


                char bufferH[NI_MAXHOST], bufferS[NI_MAXSERV];
                struct sockaddr_storage client;
                socklen_t clientlen = sizeof(client);
                char buf[200];
                char timee[64];
        e = sendto(sd,argv[3],strlen(argv[3]),0,res->ai_addr,res->ai_addrlen);

	if(e==-1){
                printf("Error al enviar comando \n");
                return -1;
        }
	freeaddrinfo(res);
        if((strcmp(argv[3],"t"))==0){
                int c = recvfrom(sd,buf,100,0,NULL,NULL);
                buf[c]='\0';
                printf("%s \n",buf);
        }
	else{
             	printf("Comando desconocido \n");
        }

	close(sd);
        return 0;
}

