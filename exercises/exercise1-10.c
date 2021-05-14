# include <stdio.h>

int main(void)
{

    
    int c;

    while ((c = getchar()) != EOF){
        
        if (c == '\t'){
            c = '\\';
            putchar(c);
            c = 't';
        }else if (c == '\\'){
                c = '\\';
                putchar(c);
                c = '\\';
        }else if(c == '\b'){
            c = '\\';
            putchar(c);
            c = 'b';
        }
        putchar(c);
    }


    return 0;
}