#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int a[2] = {10,20}; //fazer com array agora e depois com struct
    int b[2] = {30,40};
    char c = 'c'; 

    int *pa = a;
    int *pb = b;
    char *pc = &c;
    void *pp[3] = {pa,pb,pc};
    // int pp[2] = {pa,pb};

    printf("a = %d\n", *(int *)pp[0]);
    printf("b = %d\n", *(int *)pp[1]);
    printf("c = %c\n", *(char *)pp[2]);

    return 0;
}