#include <stdio.h> 

int minusculo (int c);
int transforma (char c);

//#########################################//

int main(void){
    char hex[] = "0xAAAA";
    int tamanho, i, j, soma, exp, num;
    soma = 0;
    
    //tamanho:
    for (tamanho = 0; hex[tamanho] != '\0'; tamanho++)
        hex[tamanho] = minusculo(hex[tamanho]);

    for (i = tamanho; i > 2; i--){
        exp = 1;
        num = transforma(hex[i-1]);
        for(j = (tamanho - i); j >= 1; j--){
            exp *= 16;
        }
        soma += num*exp;
    }
    printf("%d\n", soma);
    return 0;
}

//#########################################//

int minusculo (int c){
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

//#########################################//

int transforma (char c){
    if (c >= '0' && c <= '9')
        return c - '0';
    return c - 87;
}