#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main(){
    
    int **p = (int **)(malloc(2*sizeof(int *)));
    for (int i = 0; i < 2; i++ ){
        p[i] = (int *) malloc(2 * sizeof(int));
    }
    p[0][0] = 1;
    p[0][1] = 10;
    p[1][0] = 100;
    p[1][1] = 1000;


    // for (int i = 0; i < 2; i++ ){
    //     free(p[i]);
    // }

    // free(p);
    // p = (int **)(malloc(3*sizeof(int *)));
    // for (int i = 0; i < 2; i++ ){
    //     p[i] = (int *) malloc(2 * sizeof(int));
    // }
    p = (int **)realloc(p,3*sizeof(int *));
    p[2] = (int *) malloc(2 * sizeof(int));
    // for (int i = 0; i < 2; i++ ){
    //     p[i] = realloc(p[i],2 * sizeof(int));
    // }
    p[2][0] = 3000;
    // int array[3];

    // printf("%ld\n", sizeof(array));
    printf("%d\n", p[0][0]);
    printf("%d\n", p[0][1]);
    printf("%d\n", p[1][0]);
    printf("%d\n", p[1][1]);

    
}