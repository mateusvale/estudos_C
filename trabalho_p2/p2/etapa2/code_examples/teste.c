#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main(){
    // int *pa,*pb;
    // int a = 10 ,b = 20,c = 30;
    // pa = &a;
    // pb = &c;
    // *pb = *pa;
    // printf("*pa = %d\n",*pa);
    // printf("*pb = %d\n",*pb);
    // printf("Depois da mudança\n");
    // pa = &b;
    // printf("*pa = %d\n",*pa);
    // printf("*pb = %d\n",*pb);

    // char *p[2];
    // char *p1;

    // char string[4];

    // p1 = string;

    //char **p;
    // p = malloc(3 * sizeof(char*));
    //p = malloc(1);
    // char name1[] = "mateus";
    // char name2[] = "rebeca";
    // char name3[] = "lucas";
    // p[0] = name1;
    // p[1] = name2;
    // p[2] = name3;
    // printf("%s\n",*(p+1));
    //printf("%c\n",*(p+1)[0]);
    // printf("*pb = %d\n",*p);
    // printf("tamanho p1: %ld\n",sizeof(p));
    // printf("tamanho string: %ld\n",sizeof(char [3]));



    printf("#########################\n");

    char **pointer = (malloc (2 * sizeof(char[7])));
    // char name1[] = "rebeca1";
    // char name2[] = "rebeca2";
    // char name3[] = "rebeca3";

    pointer[0] = "rebeca1";
    pointer[1] = "rebeca2";
    // pointer[2] = name3;

    printf("nome1: %s\n",*pointer);
    printf("nome2: %s\n",*(pointer+1));
    printf("nome3: %s\n",*(pointer+2));
    
}