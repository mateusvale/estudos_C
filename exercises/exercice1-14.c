#include <stdio.h> 
 /* count digits, white space, others */ 
 int main(void) 
 { 
 int c, i, nwhite, nother; 
 int ndigit[93]; 
 nwhite = nother = 0; 
 for (i = 0; i < 93; ++i) 
 ndigit[i] = 0; 
 while ((c = getchar()) != EOF)
    if (c >= '!' && c <= '~')
        ++ndigit[c-'!']; 
    else if (c == ' ' || c == '\n' || c == '\t') 
        ++nwhite; 
    else 
        ++nother; 
 printf("\ndigits ="); 
 for (i = 0; i < 93; ++i) 
 printf(" %d", ndigit[i]); 
 printf(", white space = %d, other = %d\n", nwhite, nother); 
 } 
