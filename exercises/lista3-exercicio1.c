#include <stdio.h> 

#define MAXLINE 1000

int getLine (char line[], int maxLine);
void copia (char para[], char de[]);



int main(void){
    int len; //tamanho atual da linha
    char line[MAXLINE];  //linha atual
    char longest[MAXLINE]; // maior linha guardada
    int max = 0; //tamanho maximo visto ate agora

    while ((len = getLine(line, MAXLINE)) > 0){ //enquanto a linha for maior do que zero, faça:
        printf ("Len: %d\n", len);
        if (len > max) {
            max = len;
            copia(longest, line);
        }
    }
    if (max > 0){
        printf("\n%s", longest);
        printf("Len: %d\n", max);
    }
    return 0;
}

int getLine (char s[], int lim){
    int c, i; //o i sera o tamanho da string 
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){
        s[i] = c; //s eh uma string. No for, vai acrescentando caracter por caracter que foi recebido pelo getchar//
    }
    if (c == '\n'){ //se o ultimo caracter for um enter, tbm precisa ser inserido no len
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; //a string em c termina com o caracter zero '\0'. Isso indica o final da string.
    return i;
}

void copia(char para[], char de[]){
    int i = 0;
    while ((para[i] = de[i]) != '\0'){
        ++i;
    }
}

 