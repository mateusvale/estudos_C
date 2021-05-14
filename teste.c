#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    // // int a[] = {100,200,300,400,500};
    // // int b[] = {600,700,800,900,1000};
    // // int c[] = {10,20,30,40,50};
    // int *p[3];
    // int a = 1, b = 2, c = 3;
    // p[0] = &a;
    // p[1] = &b;
    // p[2] = &c;
    // //int y = (*++p)[0];

    // printf("%d\n", *p[0]);
    // printf("%d\n", *p[1]);
    // printf("%d\n", *p[2]);

    int arr1[] = {10,20};
    int arr2[] = {30,40};
    int *ap[2];
    ap[0] = arr1;
    ap[1] = arr2;
    
    printf("arr = %d\n", *++ap[1]);

}