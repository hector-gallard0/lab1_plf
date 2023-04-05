#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *componentes[] = {"IDENTIFICADOR", "ENTERO", "REAL EN NOTACION DECIMAL", "REAL EN NOTACION EXPONENCIAL", "SIMBOLO", "PALABRA RESERVADA"};

int esIdentificador(char c_str[]){
    if(strcmp(c_str, "a") == 0 || strcmp(c_str, "b") == 0 || strcmp(c_str, "c") == 0 || strcmp(c_str, "d") == 0 
    || strcmp(c_str, "e") == 0 || strcmp(c_str, "f") == 0 || strcmp(c_str, "g") == 0 || strcmp(c_str, "h") == 0
    || strcmp(c_str, "i") == 0 || strcmp(c_str, "j") == 0 || strcmp(c_str, "k") == 0 || strcmp(c_str, "l") == 0
    || strcmp(c_str, "m") == 0 || strcmp(c_str, "n") == 0 || strcmp(c_str, "o") == 0 || strcmp(c_str, "p") == 0
    || strcmp(c_str, "q") == 0 || strcmp(c_str, "r") == 0 || strcmp(c_str, "s") == 0 || strcmp(c_str, "t") == 0
    || strcmp(c_str, "u") == 0 || strcmp(c_str, "v") == 0 || strcmp(c_str, "w") == 0 || strcmp(c_str, "x") == 0
    || strcmp(c_str, "y") == 0 || strcmp(c_str, "z") == 0){
        return 1;
    }

    return 0;
}

int esEntero(char c_str[]){
    if(strcmp(c_str, "0") == 0 || strcmp(c_str, "1") == 0 || strcmp(c_str, "2") == 0 || strcmp(c_str, "3") == 0
    || strcmp(c_str, "4") == 0 || strcmp(c_str, "5") == 0 || strcmp(c_str, "6") == 0 || strcmp(c_str, "7") == 0
    || strcmp(c_str, "8") == 0 || strcmp(c_str, "9") == 0){
        return 1;
    }

    return 0;
}

int esSimbolo(char c_str[]){
    if(strcmp(c_str, "+") == 0 || strcmp(c_str, "-") == 0 || strcmp(c_str, "X") == 0 || strcmp(c_str, ":") == 0 
    || strcmp(c_str, "/") == 0 || strcmp(c_str, "^") == 0 || strcmp(c_str, "|") == 0 || strcmp(c_str, "!") == 0 
    || strcmp(c_str, "(") == 0 || strcmp(c_str, ")") == 0 || strcmp(c_str, "=") == 0){
        return 1;
    }

    return 0;
}

int esDecimal(char c_str[]){
    if(strcmp(c_str, ",") == 0){
        return 1;
    }
    
    return 0;
}

int esExponencial(char c_str[]){
    if(strcmp(c_str, "E") == 0){
        return 1;
    }

    return 0;
}

int esPalabraReservada(char c_str[]){
    if(strcmp(c_str, "A") == 0 || strcmp(c_str, "B") == 0 || strcmp(c_str, "C") == 0 || strcmp(c_str, "D") == 0 
    || strcmp(c_str, "E") == 0 || strcmp(c_str, "F") == 0 || strcmp(c_str, "G") == 0 || strcmp(c_str, "H") == 0
    || strcmp(c_str, "I") == 0 || strcmp(c_str, "J") == 0 || strcmp(c_str, "K") == 0 || strcmp(c_str, "L") == 0
    || strcmp(c_str, "M") == 0 || strcmp(c_str, "H") == 0 || strcmp(c_str, "O") == 0 || strcmp(c_str, "P") == 0
    || strcmp(c_str, "Q") == 0 || strcmp(c_str, "R") == 0 || strcmp(c_str, "S") == 0 || strcmp(c_str, "T") == 0
    || strcmp(c_str, "U") == 0 || strcmp(c_str, "V") == 0 || strcmp(c_str, "w") == 0 || strcmp(c_str, "Y") == 0 
    || strcmp(c_str, "Z") == 0 ){
        return 1;
    }

    return 0;
}

char *buscarComponente(char c_str[]){
    if(esIdentificador(c_str) == 1){
        return "IDENTIFICADOR";
    }else if(esEntero(c_str) == 1){
        return "ENTERO";
    }
    else if(esSimbolo(c_str) == 1){
        return "SIMBOLO";
    }
    // else if(esPalabraReservada() == 1){

    // }
    else if(esDecimal(c_str) == 1){
        return "REAL EN NOTACION DECIMAL";
    }
    else if(esExponencial(c_str) == 1){
        return "REAL EN NOTACION EXPONENCIAL";
    }
    else if(esPalabraReservada(c_str) == 1){
        return "PALABRA RESERVADA";
    }

    return "NULL";
}

void analizarTexto(char **text, char current_c_str[], char **current_component, FILE *fp){
    int next_c = fgetc(fp);
    char next_c_str[2] = {next_c, '\0'};
    char *next_component;
    // printf("hola" );
    next_component = buscarComponente(current_c_str);
    printf("next component -> %s\n", next_component);
    // printf("%s", next_component);
    // Si el componente de la cadena es igual al componente del caracter
    if(strcmp(*current_component, next_component) != 0){        
        // printf("son distintos");
        //Si es identificador
        if(strcmp(*current_component, componentes[0]) == 0){
            // printf("IDENTIFICADOR -> %s", *text);
        }
    }else{
        //si el componente es un identificador
        if(strcmp(*current_component, componentes[0]) == 0){
            *text = realloc(*text, (sizeof(char) * (strlen(*text) + strlen(current_c_str) + 1)));
            strcat(*text, current_c_str);    
            fseek(fp, -1L, SEEK_CUR);
        }
    }
    
    // printf("son iguales");
    // *text = realloc(*text, (sizeof(char) * (strlen(*text) + strlen(current_c_str) + 1)));
    // strcat(*text, current_c_str);    
    // fseek(fp, -1L, SEEK_CUR);
    
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
    int i = 2;
    char *componente = componentes[0];      
    // printf("%s", componente);     
    while ((c = fgetc(fp)) != EOF) {        
        char c_str[2] = {c, '\0'};  
        // printf("%s", c_str);
        analizarTexto(&text, c_str, &componente, fp);        
        // modificar(&text, c_str);
        // printf("%s", text);
        // break;
        // text = realloc(text, (sizeof(char)*i));
        // text = realloc(text, (sizeof(char)*(strlen(text) + 2)));                        
        // strcat(text, c_str);            
        // i = i + 1;
    }

    printf("\n%s", text);
    free(text);
    fclose(fp);
    return 0;
}