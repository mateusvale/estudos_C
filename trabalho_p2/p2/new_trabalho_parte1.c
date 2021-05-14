#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatriz (int *p, int x, int y);

int main(){
    int x = 7, y = 6; 
    int matrizA[x][y], *pmxA;

    int piece_D = 'D', piece_a = 'a', piece_b = 'b', piece_c = 'c', piece_d = 'd', piece_e = 'e', piece_f = 'f', piece_g = 'g', piece_h = 'h', piece_i = 'i', piece_wall = '*', piece_empty = ' '; 

    matrizA[0][0] = piece_wall, matrizA[0][1] = piece_wall, matrizA[0][2] = piece_wall, matrizA[0][3] = piece_wall, matrizA[0][4] = piece_wall, matrizA[0][5] = piece_wall;
    matrizA[1][0] = piece_wall, matrizA[1][1] = piece_a, matrizA[1][2] = piece_D, matrizA[1][3] = piece_D, matrizA[1][4] = piece_b, matrizA[1][5] = piece_wall;
    matrizA[2][0] = piece_wall, matrizA[2][1] = piece_a, matrizA[2][2] = piece_D, matrizA[2][3] = piece_D, matrizA[2][4] = piece_b, matrizA[2][5] = piece_wall;
    matrizA[3][0] = piece_wall, matrizA[3][1] = piece_c, matrizA[3][2] = piece_d, matrizA[3][3] = piece_d, matrizA[3][4] = piece_e, matrizA[3][5] = piece_wall;
    matrizA[4][0] = piece_wall, matrizA[4][1] = piece_c, matrizA[4][2] = piece_g, matrizA[4][3] = piece_h, matrizA[4][4] = piece_e, matrizA[4][5] = piece_wall;
    matrizA[5][0] = piece_wall, matrizA[5][1] = piece_f, matrizA[5][2] = piece_empty, matrizA[5][3] = piece_empty, matrizA[5][4] = piece_i, matrizA[5][5] = piece_wall;
    matrizA[6][0] = piece_wall, matrizA[6][1] = piece_wall, matrizA[6][2] = piece_empty, matrizA[6][3] = piece_empty, matrizA[6][4] = piece_wall, matrizA[6][5] = piece_wall; 

    pmxA = &matrizA[0][0];

    printMatriz (pmxA,x,y);

}

void printMatriz (int *p, int x, int y){
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++){
            printf("%c ",*(p+j+(i*y)));
        }
        printf("\n");
    }
};
