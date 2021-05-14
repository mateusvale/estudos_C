# include <stdio.h>

int toFahrenheit (int celsius);

int main(void)
{

    int celsius;

    printf("Celsius\tFahrenheit\n");
    
    for(celsius = 0; celsius <= 300 ; celsius+=20){
        printf("%6d\t%6d\n", celsius, toFahrenheit(celsius));
    }
    
    return 0;
}

int toFahrenheit (int celsius){
    return (celsius*9)/5+32;
}