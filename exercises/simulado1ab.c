#include <stdio.h>
#define TRUE 1
#define FALSE 0

void maiusculo (char s[]);
void elimina (char frase[], char cripto[], char nova[]);

int main(void){
    char cripto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
    char name1[] = "Celacanto provoca maremoto";
    char nova[30]; //30 por conta do '\0'

    maiusculo(name1);
    // printf("%s", name1);
    elimina(name1, cripto, nova);

    printf("%s\n", name1);
    printf("%s\n", nova);
    return 0;
}

void maiusculo (char s[]){
    int i = 0;
    for (;s[i] != '\0'; i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] + 'A' - 'a';
        } else
            continue;
    }
    s[i] = '\0';
}

void elimina (char frase[], char cripto[], char nova[]){
    int i, j, existe_cripto, existe_nova;
    i = j = 0;

    for (int i = 0; i<=28; i++)
        nova[i] = '0';
    nova[i] = '\0';

    for (;frase[i] != '\0'; i++){
        existe_cripto = existe_nova = FALSE;
        //para receber o caracter, existe_cripto == TRUE e existe_nova == FALSE

        for (int w = 0; w <= 28; w++){
            if (frase[i] == cripto[w]){
                existe_cripto = TRUE;
                break;
            } else
                continue;
        }
        
        for (int w = 0; w <= 28; w++){
            if (frase[i] == nova[w]){
                existe_nova = TRUE;
                break;
            } else
                continue;
        }

        if (existe_cripto == TRUE && existe_nova == FALSE){
            nova[j++] = frase[i];
        }
    }
    nova[j] = '\0';
}

