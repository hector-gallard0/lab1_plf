#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modificar(char *text, char c_str[]){
    text = realloc(text, (sizeof(char) * (strlen(text) + strlen(c_str) + 1)));
    strcat(text, c_str);    
}

int main(int argc, char* argv[]){    
    FILE *fp;
    int c;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("No se puede abrir el archivo");
        return 0;
    }

    char *text = (char*)malloc(sizeof(char));
    strcpy(text, "");
    
    while ((c = fgetc(fp)) != EOF) {        
        char c_str[2] = {c, '\0'};  
        
        modificar(text, "a");
        
    }

    printf("\n%s", text);
    free(text);
    fclose(fp);
    return 0;
}