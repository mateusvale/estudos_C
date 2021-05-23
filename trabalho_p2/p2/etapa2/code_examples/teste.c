#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main(){
    int config = 1;
    config = (config + 1 == 3) ? 1 : 2;
    // char name[2] = "c2";
    // config = name[1] - '0';
    printf("%d\n",config);
}