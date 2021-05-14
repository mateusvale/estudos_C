#include <stdio.h> 
#define MAXLINE 1000

int getLine (char line[], int maxLine);

int main(void){
    int len; 
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0){
        if (len > 1){
            printf ("%s\n", line);
        }   
    }
    return 0;
}

int getLine (char s[], int lim){
    int c, i;
    i = 0;
   
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c != ' ' && c != '\t' && (i < lim-1)){
            s[i++] = c;
        }
    }
    if (c == '\n'){ 
        s[i++] = c;
    }
    s[i] = '\0';
   
    return i;
}





 