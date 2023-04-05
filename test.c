#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE *fp;
    
    fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("No se puede abrir el archivo");
        exit(1);
    }

    fclose(fp);
    return 0;
}