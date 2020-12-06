#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Numero maximo de enlaces: %li\n",pathconf(".",_PC_LINK_MAX));
        printf("Tamano maximo de una ruta: %li\n",pathconf(".",_PC_PATH_MAX));
        printf("Tamano maximo de nombre fichero: %li\n",pathconf(".",_PC_NAME_MAX));
	return 0;
}
