#include <stdio.h>
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
                printf("%c\n",c);
                *++argv[i];
            }
        }
        
            // printf("#########\n");
    }

    // printf("c: %d\n",c);
    if (contem_c == FALSE){
        configuracao = 1;
    }
    // printf("configuracao: %d\n",configuracao);
    // printf("posicao_x: %d\n",posicao_x);
    // printf("posicao_y: %d\n",posicao_y);
    // printf("direcao: %c\n",direcao);
}