#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

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

int isDigit(char c_str[]){
    if(strcmp(c_str, "0") == 0 || strcmp(c_str, "1") == 0 || strcmp(c_str, "2") == 0 || strcmp(c_str, "3") == 0
    || strcmp(c_str, "4") == 0 || strcmp(c_str, "5") == 0 || strcmp(c_str, "6") == 0 || strcmp(c_str, "7") == 0
    || strcmp(c_str, "8") == 0 || strcmp(c_str, "9") == 0){
        return 1;
    }

    return 0;
}

int isSymbol(char c_str[]){
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
    || strcmp(c_str, "M") == 0 || strcmp(c_str, "N") == 0 || strcmp(c_str, "O") == 0 || strcmp(c_str, "P") == 0
    || strcmp(c_str, "Q") == 0 || strcmp(c_str, "R") == 0 || strcmp(c_str, "S") == 0 || strcmp(c_str, "T") == 0
    || strcmp(c_str, "U") == 0 || strcmp(c_str, "V") == 0 || strcmp(c_str, "W") == 0 || strcmp(c_str, "X") == 0 
    || strcmp(c_str, "Y") == 0 || strcmp(c_str, "Z") == 0 ) return 1;

    return 0;
}

int isSign(char c_str[]){
    if(strcmp(c_str, "-") == 0 || strcmp(c_str, "+") == 0) return 1;

    return 0;
}

int isValid(char c_str[]){
    if(isLowerLetter(c_str) == 1 || isDigit(c_str)  == 1 || isSymbol(c_str) == 1 || strcmp(c_str, ",") == 0 || strcmp(c_str, "E") == 0
    || isUpperLetter(c_str) == 1) return 1;

    return 0;
}

//Estamos asumiendo que es el primer caracter de texto
char *findComponent(char c_str[]){
    if(isLowerLetter(c_str) == 1 || isUpperLetter(c_str) == 1){        
        return "IDENTIFICADOR";
    }
    else if(isDigit(c_str) == 1){
        return "ENTERO";
    }
    else if(isSymbol(c_str) == 1){
        return "SIMBOLO";
    }

    return "NULL";
}

void concat(char **text, char c_str[]){
    *text = realloc(*text, (sizeof(char) * (strlen(*text) + strlen(c_str) + 1)));
    strcat(*text, c_str);
}

void reset(char **text){
    free(*text);
    *text = strdup("");
}

void deleteLastChar(char **text){
    int length = strlen(*text);    
    *text = realloc(*text, (sizeof(char) * (length - 1)));
    (*text)[length - 1] = '\0';    
}

void resetWithNewText(char **text, char *new_text){
    int length = strlen(new_text);    
    *text = realloc(*text, (sizeof(char) * length));
    strcpy(*text, new_text);    
}

int isReservedWord(char *text){
    if(strcmp(text, "PI") == 0 || strcmp(text, "MOD") == 0 || strcmp(text, "SQR") == 0 || strcmp(text, "CUR") == 0
    || strcmp(text, "EXP") == 0 || strcmp(text, "LN") == 0 || strcmp(text, "LOG") == 0 || strcmp(text, "SGN") == 0
    || strcmp(text, "INT") == 0 || strcmp(text, "FIX") == 0 || strcmp(text, "FRAC") == 0 || strcmp(text, "ROUND") == 0) return 1;

    return 0;
}

int hasCharacter(char *text, char character){
    if (strchr(text, character) != NULL) {        
        return 1;
    } 

    return 0;    
}

void lexicalAnalysis(char c_str[], char **text, char **text_component, FILE *fp_out){        
    if(strcmp(*text_component, "IDENTIFICADOR") == 0){              
        if(isReservedWord(*text) == 1){
            resetWithNewText(&*text_component, *text);
            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);

            reset(&*text);
            concat(&*text, c_str);     
            resetWithNewText(&*text_component, findComponent(c_str));                   
        }
        else if(isLowerLetter(c_str) == 1 || isDigit(c_str) == 1 || isUpperLetter(c_str) == 1){            
            concat(&*text, c_str);
        }
        else{
            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);
            
            reset(&*text);
            concat(&*text, c_str);     
            resetWithNewText(&*text_component, findComponent(c_str));                   
        }
    }
    else if(strcmp(*text_component, "ENTERO") == 0){
        if(isDigit(c_str) == 1){
            concat(&*text, c_str);
        }
        else if(strcmp(c_str, ",") == 0){
            concat(&*text, c_str);
            resetWithNewText(&*text_component, ",");            
        }
        else if(strcmp(c_str, "E") == 0){
            concat(&*text, c_str);
            resetWithNewText(&*text_component, "E");            
        }
        else{
            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);

            reset(&*text);
            concat(&*text, c_str);            
            resetWithNewText(&*text_component, findComponent(c_str));                  
        }
    }
    else if(strcmp(*text_component, ",") == 0){
        if(isDigit(c_str) == 1){
            concat(&*text, c_str);
            resetWithNewText(&*text_component, "DECIMAL");            
        }
        else{
            deleteLastChar(&*text);
            resetWithNewText(&*text_component, "ENTERO");      
            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);
            
            reset(&*text);
            concat(&*text, c_str);            
            resetWithNewText(&*text_component, findComponent(c_str));      
        }
    }
    else if(strcmp(*text_component, "DECIMAL") == 0){
        if(isDigit(c_str) == 1){
            concat(&*text, c_str);
        }
        else if(strcmp(c_str, "E") == 0){
            concat(&*text, c_str);
            resetWithNewText(&*text_component, "E");            
        }
        else{
            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);

            reset(&*text);
            concat(&*text, c_str);            
            resetWithNewText(&*text_component, findComponent(c_str));      
        }
    }
    else if(strcmp(*text_component, "E") == 0){
        if(isDigit(c_str) == 1){
            concat(&*text, c_str);
            resetWithNewText(&*text_component, "EXPONENCIAL");     
        }
        else if(isSign(c_str) == 1){
            concat(&*text, c_str);
            resetWithNewText(&*text_component, c_str);     
        }
        else{
            deleteLastChar(&*text);
            if(hasCharacter(*text, ',') == 0){
                resetWithNewText(&*text_component, "ENTERO");      

            }else{
                resetWithNewText(&*text_component, "DECIMAL");      
            }
            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);

            reset(&*text);
            concat(&*text, c_str);            
            resetWithNewText(&*text_component, findComponent(c_str));  
        }
    }
    else if(isSign(*text_component) == 1){
        if(isDigit(c_str) == 1){
            concat(&*text, c_str);
            resetWithNewText(&*text_component, "EXPONENCIAL");            
        }
        else{
            deleteLastChar(&*text);
            deleteLastChar(&*text);
            if(hasCharacter(*text, ',') == 0){
                resetWithNewText(&*text_component, "ENTERO");      
            }else{
                resetWithNewText(&*text_component, "DECIMAL");      
            }    

            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);

            reset(&*text);
            concat(&*text, c_str);            
            resetWithNewText(&*text_component, findComponent(c_str));  
        }
    }
    else if(strcmp(*text_component, "EXPONENCIAL") == 0){
        if(isDigit(c_str) == 1){
            concat(&*text, c_str);
        }
        else{
            // printf("%s\n", *text_component, *text);
            fprintf(fp_out, "%s\n", *text_component, *text);

            reset(&*text);
            concat(&*text, c_str);            
            resetWithNewText(&*text_component, findComponent(c_str));  
        }
    }
    else if(strcmp(*text_component, "SIMBOLO") == 0){
        // printf("%s\n", *text_component, *text);
        fprintf(fp_out, "%s\n", *text_component, *text);

        reset(&*text);
        concat(&*text, c_str);            
        resetWithNewText(&*text_component, findComponent(c_str));  
    }
    else if(strcmp(*text_component, "NULL") == 0){
        reset(&*text);
        concat(&*text, c_str);            
        resetWithNewText(&*text_component, findComponent(c_str));  
    }
}

int main(int argc, char* argv[]){             
    FILE *fp_in, *fp_out;
    int c;

    if(argc < 2){
        printf("Error: Faltan par%cmetros.\nUso: lexico.exe archivo_entrada archivo_salida\n", 160);
        return 0;
    }
    else if(argc < 3){
        printf("Error: Falta par%cmetro.\nUso: lexico.exe archivo_entrada archivo_salida\n", 160);
        return 0;
    }
    else if(argc > 3){
        printf("Error: Demasiados par%cmetros.\nUso: lexico.exe archivo_entrada archivo_salida\n", 160);
        return 0;
    }    

    fp_in = fopen(argv[1], "r");
    if (fp_in == NULL){
        printf("Error: El archivo de entrada no existe.\n");
        return 0;
    }

    fp_out = access(argv[2], F_OK ) != -1 ? NULL : fopen(argv[2], "w");    
    if(fp_out == NULL){
        printf("Error: El archivo de salida ya existe.\n");
        return 0;
    }

    char *text = (char*)malloc(sizeof(char)*15);
    strcpy(text, "");    

    char *text_component = (char*)malloc(sizeof(char));
    strcpy(text_component, "");

    int inicio = 1;
          
    while ((c = fgetc(fp_in)) != EOF) {            
        char c_str[2] = {c, '\0'};    
        int next_c = fgetc(fp_in);
        char next_c_str[2] = {next_c, '\0'};    

        if(inicio == 1){
            resetWithNewText(&text_component, findComponent(c_str));     
            inicio = 0;       
        }
        
        lexicalAnalysis(c_str, &text, &text_component, fp_out);        

        if(next_c == EOF){        
            lexicalAnalysis(next_c_str, &text, &text_component, fp_out);             
            break;
        }
        
        fseek(fp_in, -1, SEEK_CUR);
    }    
    
    free(text);
    free(text_component);
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}