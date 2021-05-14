# include <stdio.h>

int main(void)
{
    int fahr, celsius, lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;

    printf("Celsius\tFahrenheit\n");
    while (celsius < upper)
    {
        fahr = (celsius*9)/5+32;
        printf("%5d\t%12d\n", celsius, fahr);
        celsius+= step;
    }
    
    return 0;
}