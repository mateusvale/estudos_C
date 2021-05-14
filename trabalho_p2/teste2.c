#include <stdio.h>

// void printMatriz (int *arr[]);
void troca(int *pointer);

int main(){
   int b[2];
   int *p = b;
   troca(p);
   printf("%d\n", *p);
};

void troca(int *pointer){
    int a[2] = {20,30};
    pointer = &a;
    printf("%d\n", *pointer);

}

// void printMatriz (int *arr[]){
//     int i,j;
//     printf("valor 10 => %d \n",arr[0][0]);
//     printf("valor 20 => %d \n",*arr[1]);
//     printf("valor 30 => %d \n",*arr[0]);
//     printf("valor 40 => %d \n",*arr[1]);
//     for (i = 0; i < 2; i++){
//         for (j = 0; j < 2; j++){
//             printf("%d ",arr[i][j]);
//         }
//         printf("\n");
//     }
// };
