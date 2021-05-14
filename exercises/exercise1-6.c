# include <stdio.h>

int main(void)
{

    int c;
    
    printf("%d\n", (c = getchar() != EOF)); //sempre será 1
   
    return 0;
}