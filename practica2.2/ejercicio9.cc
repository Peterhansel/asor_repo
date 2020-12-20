#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	struct stat info;

	if(stat(argv[1],&info)==-1){
		perror("Fallo en stat");
		return -1;
	}

	printf("Tipo de archivo: ");
	
	switch(info.st_mode & S_IFMT){
	
		case S_IFSOCK: printf("Socket\n"); break;
		case S_IFLNK: printf("Enlace Simbolico\n"); break;
		case S_IFREG: printf("Archivo comun\n"); break;
		case S_IFBLK: printf("Dispositivo de bloques\n"); break;
		case S_IFDIR: printf("Directorio\n"); break;
		case S_IFCHR: printf("Dispositivo de caracteres\n"); break;
		case S_IFIFO: printf("FIFO\n"); break;
		default: printf("Desconocido\n"); break;
	}
	
	printf("Numero de nodo: %lo\n",(long)info.st_ino);
	printf("Major: %i\n",major(info.st_dev));
	printf("Minor: %i\n",minor(info.st_dev));
	//printf("Ultimo cambio de estado: %i", ctime(&info.st_ctim));
       // printf("Ultima modificacion: %i", ctime(&info.st_mtim));
	//error de tipos no consigo que funcione
}

	
	
