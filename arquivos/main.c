#include <stdio.h>
#include "soma.h"
#include "sub.h"
#include "mult.h"
#include "div.h"

int main (){
    int num1 = 30, num2 = 5;
    printf("soma: %d\n",soma(num1,num2));
    printf("sub: %d\n",sub(num1,num2));
    printf("mult: %d\n",mult(num1,num2));
    printf("div: %d\n",div(num1,num2));
    return 0;
}