#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	struct timeval t1;
	struct timeval t2;
	int i = 0;
	gettimeofday(&t1,NULL);
	printf("Tiempo inicio en ms: %li\n",t1.tv_usec);
	for(;i<100;i++){}
	gettimeofday(&t2,NULL);
	printf("Tiempo fin en ms: %li\n",t2.tv_usec);
	suseconds_t ms=t2.tv_usec - t1.tv_usec;
	printf("Tiempo en ms: %li\n",ms);
	return 0;
}
