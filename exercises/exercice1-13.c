#include <stdio.h> 
 #define IN 1 /* inside a word */ 
 #define OUT 0 /* outside a word */ 
 /* count lines, words, and characters in input */ 
 int main(void) 
 { 
 int c, state, nw,len; 
 state = OUT; 
 nw = len = 0; 
 while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n'){
        state = OUT;
        putchar(' ');
        printf("\tLen: %d",len);
        putchar('\n');
        putchar('\n');
        len = 0;
    }  
    else 
        if (state == OUT) { 
        state = IN; 
        ++nw;
        putchar('\n');
        putchar(c);
        // printf("\n%d\n", len);
        // putchar(len);
        len++;
    } 
        else {
            putchar(c);
            len++;
        }

 }

printf("\nNumbers of words: %d\n", nw);
} 
