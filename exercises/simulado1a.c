#include <stdio.h> 

void maiusculo (char s[]);

int main(void){
    char name1[] = "mateus do vale alexandre";

    maiusculo(name1);

    printf("%s\n", name1);
    return 0;
}

void maiusculo (char s[]){
    int i = 0;
    // char aux;
    for (;s[i] != '\0'; i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] + 'A' - 'a';
            // s[i] = aux;
        } else
            continue;
    }
    s[i] = '\0';
}



