#include <stdio.h> 

int minusculo (int c);

int main(void){
    int i = 0;
    char name1[] = "MARIA";

    for (; name1[i] != '\0'; i++){
        name1[i] = minusculo(name1[i]); 
    }

    name1[i] = '\0';

    printf("%s\n", name1);
    return 0;
}

int minusculo (int c){

    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;

}