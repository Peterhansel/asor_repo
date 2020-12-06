#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"spanish");
	time_t sec=time(NULL);
	struct tm *info=localtime(&sec);
	char strr[300];
	char *format = "%A, %d de %B de %Y, %H:%M";
	strftime(strr,300,format,info);
	printf("%s\n",strr);
	return 0;
}
