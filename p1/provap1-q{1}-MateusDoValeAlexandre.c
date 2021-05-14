#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_ELEMENTOS 1000
#define TRUE 1
#define FALSE 0

int entrada_teclado(int tamanho, char valores[]);
int transforma_para_int (char c);
void separa_inteiro(int entrada_int[], char entrada[], int tamanho);

//#######################################################################//

int main(void){
    int num, tamanho;

    char entrada[MAX_ELEMENTOS];
    int entrada_int[10];

    printf("Digite 10 valores - cada valor separado por um espaço\n");

    num = entrada_teclado(MAX_ELEMENTOS, entrada);
    tamanho = strlen(entrada);

    if (num == 10){
        separa_inteiro(entrada_int, entrada,tamanho);
    }

    float media, desvio, soma_quadrados, conta = 0;

    for (int i = 0; i < 10; i++){
        media += entrada_int[i];
        soma_quadrados += entrada_int[i]*entrada_int[i];
    }
    media /= 10;

    printf("A média é: %f\n", media);

    conta = (soma_quadrados/10) - (media*media);

    desvio = sqrt(conta);

    printf("O desvio é: %f\n", desvio);

    return 0;
}

//#######################################################################//

//AREA DE FUNCOES:

int entrada_teclado(int tamanho, char valores[]){
    int len, num, c, c_anterior;
    num = 1;
    for (len=0; len < tamanho - 1  && (c=getchar()) != EOF && c!='\n'; ++len){
        valores[len] = c;
        if (valores[len] == ' ' && c_anterior != ' '){
            num++;
        }
        c_anterior = c;
    }
    valores[len] = '\0';
    return num;
}

//#######################################################################//
int transforma_para_int (char c){
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 87;
}

//#######################################################################//
void separa_inteiro(int entrada_int[], char entrada[], int tamanho){
    int i, j, valor, w;
    i = j = valor = w =0;
    char aux[tamanho];

    int count = 0;

    for (; entrada[i] != '\0'; i++){
        count++;
        if (entrada[i] != ' '){
            aux[j++] = entrada[i];
        }
        else{
            aux[j] = '\0';
            entrada_int[w++] = atoi(aux);
            j = 0;
        }
    }
    if (count == tamanho){
            aux[j] = '\0';
            entrada_int[w++] = atoi(aux);
        }
}