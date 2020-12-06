#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	printf("UID Real: %zu\n",getuid());
	printf("UID Efectivo: %zu\n", geteuid());
	return 0;
}

//Cuando el UID es distinto al EUID se puede asegurar que el bit esta activo.
