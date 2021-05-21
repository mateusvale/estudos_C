#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

void printMatriz (int *campo, int mx, int my);

void movimentacao (int *campo, int x, int y, char direcao, int mx, int my);

int verifica_movimentacao (int *campo, int x, int y, char direcao, int mx, int my);

int *quantpecas_localidade (int *campo, int peca, int mx, int my);

void traducao_direcao(char direcao);

int main (int argc, char *argv[]){
    int configuracao, x = 7, y, c = 0,direcao,local_m = 1000; //colocar um valor alto para local_m

    int contem_c = FALSE;
    int contem_m = FALSE;
    int posicao_x, posicao_y;
    int anterior = 0;

    for (int i = 0; i < argc; i++){
        if (i != 0){
            while ((c = *argv[i])){
                if (c == 'c'){
                    contem_c = TRUE;
                }
                if (anterior == 'c' && c == '1'){
                    configuracao = 1;
                }
                if (anterior == 'c' && c == '2'){
                    configuracao = 2;
                }
                if (c == 'm'){
                    contem_m = TRUE;
                    local_m = i;
                }
                if ((local_m + 1) == i){
                    posicao_x = c - '0';
                }
                if ((local_m + 2) == i){
                    posicao_y = c - '0';
                }
                if (c == 'T' || c == 'B' || c == 'E' || c == 'D'){
                    direcao = c;
                }
                ++argv[i];
                anterior = c;
            }
        }
    }

    if (contem_c == FALSE){
        configuracao = 1;
    }

    y = (configuracao == 1) ? 6: 8;

    int matrizA[x][y], *campo;

    if (configuracao == 1){

        matrizA[0][0] = '*', matrizA[0][1] = '*', matrizA[0][2] = '*', matrizA[0][3] = '*', matrizA[0][4] = '*', matrizA[0][5] = '*';
        matrizA[1][0] = '*', matrizA[1][1] = 'a', matrizA[1][2] = 'D', matrizA[1][3] = 'D', matrizA[1][4] = 'b', matrizA[1][5] = '*';
        matrizA[2][0] = '*', matrizA[2][1] = 'a', matrizA[2][2] = 'D', matrizA[2][3] = 'D', matrizA[2][4] = 'b', matrizA[2][5] = '*';
        matrizA[3][0] = '*', matrizA[3][1] = 'c', matrizA[3][2] = 'd', matrizA[3][3] = 'd', matrizA[3][4] = 'e', matrizA[3][5] = '*';
        matrizA[4][0] = '*', matrizA[4][1] = 'c', matrizA[4][2] = 'g', matrizA[4][3] = 'h', matrizA[4][4] = 'e', matrizA[4][5] = '*';
        matrizA[5][0] = '*', matrizA[5][1] = 'f', matrizA[5][2] = ' ', matrizA[5][3] = ' ', matrizA[5][4] = 'i', matrizA[5][5] = '*';
        matrizA[6][0] = '*', matrizA[6][1] = '*', matrizA[6][2] = '+', matrizA[6][3] = '+', matrizA[6][4] = '*', matrizA[6][5] = '*'; 
    } else{
        matrizA[0][0] = '*', matrizA[0][1] = '*', matrizA[0][2] = '*', matrizA[0][3] = '*', matrizA[0][4] = '*', matrizA[0][5] = '*',matrizA[0][6] = '*',matrizA[0][7] = '*';
        matrizA[1][0] = '*', matrizA[1][1] = 'D', matrizA[1][2] = 'D', matrizA[1][3] = ' ', matrizA[1][4] = 'a', matrizA[1][5] = 'a',matrizA[1][6] = 'b',matrizA[1][7] = '*';
        matrizA[2][0] = '*', matrizA[2][1] = 'D', matrizA[2][2] = 'D', matrizA[2][3] = ' ', matrizA[2][4] = 'a', matrizA[2][5] = 'c',matrizA[2][6] = 'd',matrizA[2][7] = '*';
        matrizA[3][0] = '*', matrizA[3][1] = 'e', matrizA[3][2] = 'e', matrizA[3][3] = 'f', matrizA[3][4] = 'g', matrizA[3][5] = 'd',matrizA[3][6] = 'd',matrizA[3][7] = '*';
        matrizA[4][0] = '*', matrizA[4][1] = 'h', matrizA[4][2] = 'h', matrizA[4][3] = 'i', matrizA[4][4] = 'j', matrizA[4][5] = 'k',matrizA[4][6] = 'l',matrizA[4][7] = '+';
        matrizA[5][0] = '*', matrizA[5][1] = 'h', matrizA[5][2] = 'i', matrizA[5][3] = 'i', matrizA[5][4] = 'm', matrizA[5][5] = 'k',matrizA[5][6] = 'l',matrizA[5][7] = '+';
        matrizA[6][0] = '*', matrizA[6][1] = '*', matrizA[6][2] = '*', matrizA[6][3] = '*', matrizA[6][4] = '*', matrizA[6][5] = '*',matrizA[6][6] = '*',matrizA[6][7] = '*';
    }

    campo = &matrizA[0][0];

    printMatriz (campo,x,y);

    if (contem_m == TRUE){
        movimentacao(campo, posicao_x, posicao_y, direcao, x, y);
    }

}

//#################################################################################

void printMatriz (int *campo, int mx, int my){
    printf("\n");
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
    if (x > mx || y > my){
        return FALSE;
    }
    int local_peca = my*y + x;
    int peca = *(campo+local_peca);
    int *count_e_localidade;
    count_e_localidade = quantpecas_localidade(campo, peca, mx, my); //(count,x,x,x,x)
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
        }
    if (quantidade == 4 && peca_vazia == 2 && peca_mesma ==2){
        return TRUE;
    } //colocar 3 pecas aqui por conta do tabuleiro 2
    else if(quantidade == 3 && peca_vazia == 2 && peca_mesma == 1){
        return TRUE;
    }
    else if ((quantidade == 2 && peca_vazia == 1 && peca_mesma == 1) || (quantidade == 2 && peca_vazia == 2 && peca_mesma == 0)){
        return TRUE;
    }
    else if (quantidade == 1 && peca_vazia == 1 && peca_mesma ==0){
        return TRUE;
    } else return FALSE;

}

void traducao_direcao(char direcao){
    switch (direcao){
    case 'B':
        printf("baixo\n");
        break;
    case 'T':
        printf("topo\n");
        break;
    case 'E':
        printf("esquerda\n");
        break;
    case 'D':
        printf("direita\n");
        break;      
    default:
        printf("nenhum lugar\n");
    }
}

void movimentacao (int *campo, int x, int y, char direcao, int mx, int my){
    if (verifica_movimentacao(campo,x,y,direcao,mx,my) == 0){

        printf("\nImpossível movimentar peça em %d,%d para ", x,y);
        traducao_direcao(direcao);
    }
    else{
        int local_peca = my*y + x;
        int peca = *(campo+local_peca);
        int *count_e_localidade;
        count_e_localidade = quantpecas_localidade(campo, peca, mx, my); //(count,x,x,x,x)
        int quantidade = *count_e_localidade;
        int aux[quantidade];

        if (direcao == 'D'){
            for (int i = 0; i < quantidade; i++){
                *(campo+( *(count_e_localidade+1+i)+1)) = peca;
                aux[i] = *(count_e_localidade+1+i)+1;
            }
        }
        else if (direcao == 'E'){
            for (int i = 0; i < quantidade; i++){
                *(campo+( *(count_e_localidade+1+i)-1)) = peca;
                aux[i] = *(count_e_localidade+1+i)-1;
            }
            
        }
        else if (direcao == 'B'){
            for (int i = 0; i < quantidade; i++){
                *(campo+( *(count_e_localidade+1+i)+my)) = peca;
                aux[i] = *(count_e_localidade+1+i)+my;
            }
        } else {
            for (int i = 0; i < quantidade; i++){

                *(campo+( *(count_e_localidade+1+i)-my)) = peca;
                aux[i] = *(count_e_localidade+1+i)-my;
            }
        }
        int pode_apagar; 
        for (int i = 0; i < quantidade; i++){
            pode_apagar = TRUE; 
            for (int j = 0; j < quantidade; j++){
                if(*(count_e_localidade+1+i) == aux[j]){
                    pode_apagar = FALSE;
                    break;
                }
            }
            if (pode_apagar == TRUE){
                *(campo+( *(count_e_localidade+1+i))) = ' ';
            }    
        }
        printMatriz (campo,mx,my);
    }
}