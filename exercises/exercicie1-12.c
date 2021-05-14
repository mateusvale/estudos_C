#include <stdio.h> 
 #define IN 1 /* inside a word */ 
 #define OUT 0 /* outside a word */ 
 /* count lines, words, and characters in input */ 
 int main(void) 
 { 
 int c, state; 
 state = OUT; 
//  nl = nw = nc = 0; 
 while ((c = getchar()) != EOF) {
    // ++nc; 
    // if (c == '\n')  ++nl; 
    if (c == ' ' || c == '\t') state = OUT; 
    else 
        if (state == OUT) { 
        state = IN; 
        putchar('\n');
        putchar(c);
    } 
        else putchar(c);
 } 
//  printf("\n%d %d %d\n", nl, nw, nc); 
 } 
