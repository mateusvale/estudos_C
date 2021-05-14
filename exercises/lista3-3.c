#include <stdio.h> 
#define MAXLINE 1000

int getLine (char line[], int maxLine);
void inverte (char de[], char para[]);

int main(void){
    int len; 
    char line[MAXLINE];
    char invertido[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0){
        if (len > 1){
            inverte(line, invertido);
            printf ("%s\n", invertido);
        }   
    }
    return 0;
}

int getLine (char s[], int lim){
    int c, i; 
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){ 
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

void inverte (char de[], char para[]){
    int i,j,tamanho;
    for (i = 0; de[i] != '\0'; i++);
    --i; //retira o caracter pula linha
    j = tamanho = i;
    ++j; //para acrescentar o fecha string '\0'
    for (;i >= 0; i--){
        para[tamanho-i] = de[i];
    }
    para[j] = '\0';
}


 