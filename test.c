#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isLowerLetter(char c_str[]){
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

int esDigito(char c_str[]){
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

int isUpperLetter(char c_str[]){
    if(strcmp(c_str, "A") == 0 || strcmp(c_str, "B") == 0 || strcmp(c_str, "C") == 0 || strcmp(c_str, "D") == 0 
    || strcmp(c_str, "E") == 0 || strcmp(c_str, "F") == 0 || strcmp(c_str, "G") == 0 || strcmp(c_str, "H") == 0
    || strcmp(c_str, "I") == 0 || strcmp(c_str, "J") == 0 || strcmp(c_str, "K") == 0 || strcmp(c_str, "L") == 0
    || strcmp(c_str, "M") == 0 || strcmp(c_str, "H") == 0 || strcmp(c_str, "O") == 0 || strcmp(c_str, "P") == 0
    || strcmp(c_str, "Q") == 0 || strcmp(c_str, "R") == 0 || strcmp(c_str, "S") == 0 || strcmp(c_str, "T") == 0
    || strcmp(c_str, "U") == 0 || strcmp(c_str, "V") == 0 || strcmp(c_str, "w") == 0 || strcmp(c_str, "Y") == 0 
    || strcmp(c_str, "Z") == 0 ) return 1;

    return 0;
}

void concat(char **text, char c_str[]){
    *text = realloc(*text, (sizeof(char) * (strlen(*text) + strlen(c_str) + 1)));
    strcat(*text, c_str);
}

int isValid(char c_str[]){
    if(isLowerLetter(c_str) == 1 || esDigito(c_str)  == 1 || esSimbolo(c_str) == 1 || strcmp(c_str, ",") == 0 || strcmp(c_str, "E") == 0
    || isUpperLetter(c_str) == 1) return 1;

    return 0;
}

void lexicalAnalysis(char c_str[], char next_c_str[], char **text, char **text_component){
    printf("%s, %s\n", c_str, next_c_str);

    if(isLowerLetter(c_str) == 1){
        if(isLowerLetter(next_c_str) == 1){
            concat(&text, c_str);
        }
        else if(isUpperLetter(c_str) == 1){

        }
    }
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
    char *text_component = (char*)malloc(sizeof(char));
    strcpy(text_component, "");

    int inicio = 1;
          
    while ((c = fgetc(fp)) != EOF) {            
        char c_str[2] = {c, '\0'};    
        int next_c = fgetc(fp);
        char next_c_str[2] = {next_c, '\0'};

        if(isValid(c_str) == 1){
            lexicalAnalysis(c_str, next_c_str, &text, &text_component);
        }    

        if(next_c == EOF){
            break;
        }
        
        
        fseek(fp, -1, SEEK_CUR);
    }    
    printf("\n%s", text);
    free(text);
    fclose(fp);
    return 0;
}