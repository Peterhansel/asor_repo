#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <string.h>

int main(int argc, char **argv){
	struct addrinfo hints, *res;
	char buf[100];

	memset(&hints,0,sizeof(struct addrinfo));
	hints.ai_flags=AI_PASSIVE;
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;

	if(argc!=3){
		printf("Debe de haber dos argumentos exactamente \n");
		return -1;
	}

	int e = getaddrinfo(argv[1],argv[2],&hints,&res);
	
	if(e!=0){
		printf("Ha habido un error al obtener la direccion \n");
		return -1;
	}
	
	int sd = socket(res->ai_family,res->ai_socktype,0);
	
	if(sd==-1){
		printf("Error al crear el socket general \n");
		return -1;
	}	
	
	e = connect(sd,(struct sockaddr *)res->ai_addr,res->ai_addrlen);
	if(e!=0){
		printf("Conexion fallida \n");
		return -1;
	}
	int bytes=read(0,buf,100);
        buf[bytes]='\0';
	while(strcmp(buf,"Q\n")){
		send(sd,buf,bytes,0);
		bytes=recv(sd,buf,100,0);
		buf[bytes]='\0';
		printf(buf);
		bytes=read(0,buf,100);
        	buf[bytes]='\0';
	}
	close(sd);
	return 0;
}
