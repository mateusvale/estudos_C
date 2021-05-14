#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatriz (int *arr[]);

int main(){

    int a[2][2], *p;

    int la = 10, lb = 20, lc = 30, ld = 40;

    a[0][0] = la;
    a[0][1] = lb;
    a[1][0] = lc;
    a[1][1] = ld;

    p = &a[0][0];

    printf("valor 10 => %d \n",*p);
    printf("valor 20 => %d \n",*(p+1));
    printf("valor 30 => %d \n",*(p+2));
    printf("valor 40 => %d \n",*(p+3));


    // printMatriz(*a);
    

};

void printMatriz (int *arr[]){
    int i,j;
    printf("valor 10 => %d \n",*arr[0]);
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
