#include <stdio.h>

void printMatriz (int *arr[]);

int main(){

    int a = 'a';
    int b = 'd';

    if (a == 'a'){
        printf("Sim");
    }


    // printf("valor => %f \n", pow(a,b));
    // int teste[2][2];
    // int (*a)[2][2] = teste;

    // int la = 10, lb = 20, lc = 30, ld = 40;

    // teste[0][0] = la;
    // teste[0][1] = lb;
    // teste[1][0] = lc;
    // teste[1][1] = ld;

    // printf("valor 10 => %d \n",*(a[0][0]));
    // printf("valor 20 => %d \n",*(a[0][1]));
    // printf("valor 30 => %d \n",*(a[1][0]));
    // printf("valor 40 => %d \n",*(a[1][1]));


    // printf("%c\n",*a[0][0]);
    // printf("%c\n",*a[0][1]);
    // printf("%c\n",*a[1][0]);
    // printf("%c\n",*a[1][1]);
    // printf("%d\n",*(*ab[0])[2]);

    //printMatriz(*a);
    

};

void printMatriz (int *arr[]){
    int i,j;
    printf("valor 10 => %d \n",arr[0][0]);
    printf("valor 20 => %d \n",*arr[1]);
    printf("valor 30 => %d \n",*arr[0]);
    printf("valor 40 => %d \n",*arr[1]);
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
};
