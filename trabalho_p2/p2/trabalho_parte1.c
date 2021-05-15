#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

void printMatriz (int *campo, int mx, int my); //funciona

void movimentacao (int *campo, int x, int y, char direcao, int mx, int my);

int verifica_movimentacao (int *campo, int x, int y, char direcao, int mx, int my); //funciona

int *quantpecas_localidade (int *campo, int peca, int mx, int my); //funciona

int main(){
    int x = 7, y = 6; 

    int matrizA[x][y], *campo;

    matrizA[0][0] = '*', matrizA[0][1] = '*', matrizA[0][2] = '*', matrizA[0][3] = '*', matrizA[0][4] = '*', matrizA[0][5] = '*';
    matrizA[1][0] = '*', matrizA[1][1] = 'a', matrizA[1][2] = 'D', matrizA[1][3] = 'D', matrizA[1][4] = 'b', matrizA[1][5] = '*';
    matrizA[2][0] = '*', matrizA[2][1] = 'a', matrizA[2][2] = 'D', matrizA[2][3] = 'D', matrizA[2][4] = 'b', matrizA[2][5] = '*';
    matrizA[3][0] = '*', matrizA[3][1] = 'c', matrizA[3][2] = 'd', matrizA[3][3] = 'd', matrizA[3][4] = 'e', matrizA[3][5] = '*';
    matrizA[4][0] = '*', matrizA[4][1] = 'c', matrizA[4][2] = 'g', matrizA[4][3] = 'h', matrizA[4][4] = 'e', matrizA[4][5] = '*';
    matrizA[5][0] = '*', matrizA[5][1] = 'f', matrizA[5][2] = ' ', matrizA[5][3] = ' ', matrizA[5][4] = 'i', matrizA[5][5] = '*';
    matrizA[6][0] = '*', matrizA[6][1] = '*', matrizA[6][2] = '+', matrizA[6][3] = '+', matrizA[6][4] = '*', matrizA[6][5] = '*'; 

    campo = &matrizA[0][0];


    //########teste função printMatriz########//
    printMatriz (campo,x,y);
    //########teste função printMatriz########//
    
    //########teste função verifica_movimentacao########//
    printf("\nPosso movimentar? %d\n",verifica_movimentacao (campo, 2, 1, 'T', x, y));
    //########teste função verifica_movimentacao########//

    //########teste função quantpecas_localidade########//
    // int *peca;
    // peca = quantpecas_localidade(campo, ' ', x, y); 

    // printf("%d\n",*peca);
    // printf("%d\n",*(peca+1));
    // printf("%d\n",*(peca+2));
    // printf("%d\n",*(peca+3));
    // printf("%d\n",*(peca+4));
    //########teste função quantpecas_localidade########//

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
    int total = mx*my, i = 0, count = 0, *count_e_localidade;
    static int arr1[30]; //numero alto para ser maior do que a quantidade de '*'
    for (;i <= total; i++){
        if (*(campo+i) == peca){
            arr1[count++] = i;
        }
    }
    arr1[count] = 's';
    static int arr2[30];
    arr2[0] = count;
    for (int j = 0;arr1[j] != 's'; j++){
        arr2[j+1] = arr1[j];
    }
    count_e_localidade = arr2;
    return count_e_localidade;
}


int verifica_movimentacao (int *campo, int x, int y, char direcao, int mx, int my){
    int local_peca = my*x + y;

    printf("local da peça = %d\n",local_peca);

    int peca = *(campo+local_peca);

    printf("peça = %c\n",peca);

    int *count_e_localidade;
    count_e_localidade = quantpecas_localidade(campo, peca, mx, my); //(count,x,x,x,x)

    printf("%d\n",*count_e_localidade);
    printf("%d\n",*(count_e_localidade+1));

    int quantidade = *count_e_localidade;
    int peca_vazia = 0, peca_mesma = 0;
    //Para o movimento da peca for valido, quando houver a movimentacao,
    //metade de seu corpo irá para o vazio e a outra metade irá para o lugar que era sua peca 
    //a afirmacao acima é só quando a peca tem 4 ou 2 tamanhos, pois caso seja 1 tamanho, ele vai direto para o vazio
    //T B E D

    if (peca != ' ' || peca != '*' || peca != '+'){
        if (direcao == 'D'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)+1 )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)+1 )) == peca){
                    peca_mesma++;
                }
            }

        }
        else if (direcao == 'E'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)-1 )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)-1 )) == peca){
                    peca_mesma++;
                }
            }
            
        }
        else if (direcao == 'B'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)+my )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)+my )) == peca){
                    peca_mesma++;
                }
            }


        } else if(direcao == 'T'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)-my )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)-my )) == peca){
                    peca_mesma++;
                }
            }

        } else return FALSE;

    }
        else{
            return FALSE;
            // printf("Movimento Inválido\n");
        }
    printf("quantidade = %d\n",quantidade);
    printf("peca_vazia = %d\n",peca_vazia);
    printf("peca_mesma = %d\n",peca_mesma);

    if (quantidade == 4 && peca_vazia == 2 && peca_mesma ==2){
        return TRUE;
    }
    else if ((quantidade == 2 && peca_vazia == 1 && peca_mesma == 1) || (quantidade == 2 && peca_vazia == 2 && peca_mesma == 0)){
        return TRUE;
    }
    else if (quantidade == 1 && peca_vazia == 1 && peca_mesma ==0){
        return TRUE;

    } else return FALSE;

}
