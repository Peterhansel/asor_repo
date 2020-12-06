#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	time_t sec=time(NULL);
	struct tm *info=localtime(&sec);
	printf("Years since EPOCH(1900): %li\n",info->tm_year);
	int year = info->tm_year+1900;
	printf("Current year: %li\n",year);
	return 0;
}
