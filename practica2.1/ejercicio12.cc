#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	time_t tm;
	time(&tm);
	printf("Tiempo en segundos desde EPOCH: %i\n",tm);
	return 0;
}
