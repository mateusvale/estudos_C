# include <stdio.h>

int main(void)
{

    
    int c, count = 0, aux;

    while ((c = getchar()) != EOF){
        if (c == ' ') 
            count++;
        else
            if (count > 1){
                aux = c;
               while (count != 1){    
                   c = '\b';
                   putchar(c);
                   --count;
               }
                c = aux;
            }
            else count = 0;
        putchar(c);
    }

    return 0;
}