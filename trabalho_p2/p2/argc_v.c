#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main (int argc, char *argv[]){
    int configuracao, x = 7, y, c = 0,count = 0, direcao,local_m = 1000; //colocar um valor alto para local_m

    int contem_c = FALSE;
    int posicao_x, posicao_y;
    int anterior = 0;

    for (int i = 0; i < argc; i++){
        if (i != 0){
            while ((c = *argv[i])){
                // printf("##########\n");
                // printf("anterior: %c\n", anterior);
                // printf("Caracter c: %c\n",c);
                if (c == 'c'){
                    // printf("contem C\n");
                    contem_c = TRUE;
                }
                if (anterior == 'c' && c == '1'){
                    // printf("configuracao 1\n");
                    configuracao = 1;
                }
                if (anterior == 'c' && c == '2'){
                    // printf("configuracao 2\n");
                    configuracao = 2;
                }
                if (c == 'm'){
                    // printf("Local do m\n");
                    local_m = i;
                }
                if ((local_m + 1) == i){
                    // printf("Posicao do x\n");
                    posicao_x = (int) c;
                }
                if ((local_m + 2) == i){
                    // printf("Posicao do y\n");
                    posicao_y = (int) c;
                }
                if (c == 'T' || c == 'B' || c == 'E' || c == 'D'){
                    // printf("Posicao da direcao\n");
                    direcao = c;
                }
                *++argv[i];
                anterior = c;
                count++;
            }
        }
    }

    // printf("##########################################\n");
    if (contem_c == FALSE){
        configuracao = 1;
    }

    // int novox = atoi(posicao_x);
    int intposicao_x = posicao_x - '0';
    int intposicao_y = posicao_y - '0';

    printf("configuracao: %d\n",configuracao);
    printf("posicao_x: %d\n",intposicao_x);
    printf("posicao_y: %d\n",intposicao_y);
    printf("direcao: %c\n",direcao);
}