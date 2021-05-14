#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatriz (int *campo, int mx, int my);

void movimentacao (int *campo, int x, int y, char direcao, int mx, int my);

void verifica_movimentacao (int *campo, int x, int y, char direcao, int mx, int my);

int *quantpecas_localidade (int *campo, int peca, int mx, int my); 

int main(){
    int x = 7, y = 6; 

    int matrizA[x][y], *campo;

    matrizA[0][0] = '*', matrizA[0][1] = '*', matrizA[0][2] = '*', matrizA[0][3] = '*', matrizA[0][4] = '*', matrizA[0][5] = '*';
    matrizA[1][0] = '*', matrizA[1][1] = 'a', matrizA[1][2] = 'D', matrizA[1][3] = 'D', matrizA[1][4] = 'b', matrizA[1][5] = '*';
    matrizA[2][0] = '*', matrizA[2][1] = 'a', matrizA[2][2] = 'D', matrizA[2][3] = 'D', matrizA[2][4] = 'b', matrizA[2][5] = '*';
    matrizA[3][0] = '*', matrizA[3][1] = 'c', matrizA[3][2] = 'd', matrizA[3][3] = 'd', matrizA[3][4] = 'e', matrizA[3][5] = '*';
    matrizA[4][0] = '*', matrizA[4][1] = 'c', matrizA[4][2] = 'g', matrizA[4][3] = 'h', matrizA[4][4] = 'e', matrizA[4][5] = '*';
    matrizA[5][0] = '*', matrizA[5][1] = 'f', matrizA[5][2] = ' ', matrizA[5][3] = ' ', matrizA[5][4] = 'i', matrizA[5][5] = '*';
    matrizA[6][0] = '*', matrizA[6][1] = '*', matrizA[6][2] = ' ', matrizA[6][3] = ' ', matrizA[6][4] = '*', matrizA[6][5] = '*'; 

    campo = &matrizA[0][0];

    printMatriz (campo,x,y);

    //verificar todas as letras e fazer a transformação para sexdecimal
    int *peca = quantpecas_localidade(campo, 'b', x, y); 

    printf("%d\n",*peca);
    printf("%d\n",*(peca+1));
    printf("%d\n",*(peca+2));
    printf("%d\n",*(peca+3));
    printf("%d\n",*(peca+4));

}

void printMatriz (int *campo, int mx, int my){
    int i, j;
    for (i = 0; i < mx; i++){
        for (j = 0; j < my; j++){
            printf("%c ",*(campo+j+(i*my)));
        }
        printf("\n");
    }
};

int *quantpecas_localidade (int *campo, int peca, int mx, int my){
    int total = mx*my, i = 0, count = 0, arr1[5], *ponteiro;
    for (;i <= total; i++){
        if (*(campo+i) == peca){
            arr1[count++] = i;//sexdecimal(i); //passar para sexdecimal 
        }
    }
    arr1[count] = 's';
    int arr2[count+1];
    arr2[0] = count;
    for (int j = 0;arr1[j] != 's'; j++){
        arr2[j+1] = arr1[j];
    }
    ponteiro = arr2;
    return ponteiro;
}


void verifica_movimentacao (int *p, int x, int y, char direcao, int mx, int my){
    int local_peca = my*x + y;
    if (*(p+local_peca) == ' ' || *(p+local_peca) == '*'){
        printf("Movimento Inválido\n");
    } else{

    }
}

