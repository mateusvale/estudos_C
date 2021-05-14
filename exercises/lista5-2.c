#include <stdio.h> 
#define TRUE 1
#define FALSE 0

void comprimeAlternativo(char string1[], char string2[]);

int main(void){
    char name1[] = "Maria";
    char name2[] = "Marta";
    comprimeAlternativo(name1, name2);
    printf("%s\n", name1);
    return 0;
}

void comprimeAlternativo(char s1[], char s2[]){
    int i, j, casa, w;
    for(i = j = 0; s1[i] != '\0'; i++){
        casa = FALSE;
        for (w = 0; s2[w] != '\0'; w++){
            if (s1[i] == s2[w]){
                casa = TRUE;
                break;
            }
        }
        if (casa == FALSE){
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}