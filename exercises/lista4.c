#include <stdio.h> 
#define TRUE 1
#define FALSE 0
#define MAX 1000000

int ePrimo (int valor, int count, int numPrimo[]);

int main(void){
    int count = 1 ;
    int valor;
    int numPrimo[MAX];
    numPrimo[0] = valor = 2;

    while (count != (MAX)){
        // valor++;
        // if (valor%2 != 0){
           if (++valor%2 != 0){ 
            if ((ePrimo(valor, count, numPrimo)) == TRUE){
                numPrimo[count++] = valor;
                // numPrimo[count] = valor;
                // count++;
            }
        }
    }
    printf("%d\n", numPrimo[count-1]);
    return 0;
}

int ePrimo (int valor, int count, int numPrimo[]){
    int i = 0;
    int state = FALSE;
    while (i < count ){
        if (valor % numPrimo[i] == 0){
            break;
        }else
            if (numPrimo[i] > valor / numPrimo[i]){
                state = TRUE;
                break;
            } 
            else ++i;
    }
    return state;
}