#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	struct stat info;
	
	char slink[255];
	char hlink[255];
	
	
	strcpy(slink, argv[1]);
	strcat(slink,".sym");
	strcpy(hlink, argv[1]);
	strcat(hlink,".hard");
	
	if ((info.st_mode & S_IFMT)== S_IFREG){
		symlink(argv[1],slink);
		link(argv[1],hlink);
	}

	return 0;
}
