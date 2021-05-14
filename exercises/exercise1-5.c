# include <stdio.h>

int main(void)
{

    int fahr;

    printf("Fahrenheit\tCelsius\n");
    
    for(fahr = 300; fahr >= 0; fahr-=20){
        printf("%6d\t%13d\n", fahr, (5 * (fahr-32) / 9));
    }
    
    return 0;
}