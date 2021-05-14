#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAXLINE 1000

void maiusculo (char s[]);
int elimina (char frase[], char cripto[], char nova[]);
void completa (char nova[], char cripto[], int parada);
void converte (char nova[], char cripto[], char convertida[], char name[]);


int main(void){
    int parada, i, c;
    char cripto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
    char frase[] = "Celacanto provoca maremoto";
    char name[MAXLINE];
    char nova[30];       //30 (29 + 1) por conta do '\0'
    char convertida[30]; //30 (29 + 1) por conta do '\0'

    maiusculo(frase);

    parada = elimina(frase, cripto, nova);

    completa(nova, cripto, parada);

    for (i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i){
        name[i] = c;
    }
    name[i] = '\0';

    maiusculo(name);

    converte(nova,cripto,convertida, name);

    printf("%s\n", frase);
    printf("%s\n", nova);
    printf("%s\n", convertida);

    return 0;
}

void maiusculo (char s[]){
    int i = 0;
    for (;s[i] != '\0'; i++){
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] + 'A' - 'a';
    }
    s[i] = '\0';
}

int elimina (char frase[], char cripto[], char nova[]){
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
    return j;
}

void completa (char nova[], char cripto[], int parada){
    int existe_nova;
    for (int i = 0; cripto[i] != '\0'; i++){
        existe_nova = FALSE;
        for (int j = 0; nova[j] != '\0'; j++){

            if (cripto[i] == nova[j]){
                existe_nova = TRUE;
                break;
            }
        }
        if (existe_nova == FALSE){
            nova[parada++] = cripto[i];
            nova[parada] = '\0';
        }
    }
}

void converte (char nova[], char cripto[], char convertida[], char name[]){
    int i, j, local;
    j = local = 0;

    while (name[j] != '\0'){
        i = 0;
        for (; cripto[i] != '\0'; i++){
            if (name[j] == cripto[i]){   //peguei o valor do indice e o valor do caracter
                break;
            }
        }
        local += ((++i + local) < 29) ? i : i - 29;
        convertida[j++] = nova[local];
    }
    convertida[j] = '\0';
}