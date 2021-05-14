# include <stdio.h>

int main(void)
{

    
    int c, nl = 0, tab = 0, blank = 0; 

    while ((c = getchar()) != EOF){
        if (c == ' ') 
            ++blank;
        if (c == '\n') 
            ++nl;
        if (c == '\t') 
            ++tab;
    } 
    
     
    printf("\nNumber of newlines: %d\n", nl); 
    printf("Number of tabs: %d\n", tab);
    printf("Number of blanks: %d\n", blank);
   


   
    return 0;
}