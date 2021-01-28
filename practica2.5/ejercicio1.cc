#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>

int main(int argc, char **argv){
	
	struct addrinfo *res;
	struct addrinfo *lista;
	
	struct addrinfo hints;

	memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
        hints.ai_socktype = 0; /* Datagram socket */
        hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
        hints.ai_protocol = 0;          /* Any protocol */
        hints.ai_canonname = NULL;
        hints.ai_addr = NULL;
        hints.ai_next = NULL;

	int e = getaddrinfo(argv[1],NULL,&hints,&res);
		
	if(e!=0){
		printf("Hubo un error al intentar conseguir la info \n");
		return -1;
	}
	for(lista=res;lista!=NULL;lista= lista->ai_next){
		char bufferH[NI_MAXHOST];
		e = getnameinfo(lista->ai_addr,lista->ai_addrlen, bufferH,NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
		if(e!=0){
			printf("Error al traducir el host y servicio \n");
			return -1;
		}
		printf("IP: %s , Protocolo: %i , Tipo de Socket: %i \n", bufferH, lista->ai_protocol, lista->ai_socktype ); 
	}
	return 0;
}
