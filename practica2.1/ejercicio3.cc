#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    int i = 0;
    for(; i < 255; i++){
        printf("Error: %i - %s", i, strerror(i));
    }
    return 0;
}
//A partir del tipo de error 134 todos los errores son desconocidos debido a que solo hay 134 tipos de error.
