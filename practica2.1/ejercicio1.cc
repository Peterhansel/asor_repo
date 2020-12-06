#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
	if(setuid(0)==-1){
		perror("Error:");
	}
	else{
		printf("No Error");
	}
	return 1;
}
