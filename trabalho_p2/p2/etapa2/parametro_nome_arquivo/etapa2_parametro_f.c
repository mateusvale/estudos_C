#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main (int argc, char *argv[]){
    int c,count_letter = 0, anterior = 0, flag_name = FALSE;

    int contem_f = FALSE;
    char nome_arquivo_array[100];
    char *nome_arquivo;  
    nome_arquivo = nome_arquivo_array;

    if (argc == 3){
        for (int i = 0; i < argc; i++){
            if (i != 0){        //não pega o nome da execução do programa
                while ((c = *argv[i])){
                    if (c == 'f' && anterior == '-'){
                        contem_f = TRUE;
                    }
                    if (anterior == 'f' && contem_f == TRUE){
                        flag_name = TRUE;
                    }
                    if (flag_name == TRUE){
                        nome_arquivo_array[count_letter++] = c;
                    }
                    ++argv[i];
                    anterior = c;
                }
            }
        }
        nome_arquivo_array[count_letter] = '\0';
    }
    if (contem_f == FALSE){
        char novo_nome[] = "haikori.txt";
        nome_arquivo = novo_nome;
    }
    for (int i= 0; *(nome_arquivo+i) != '\0'; i++){
        printf("%c",*(nome_arquivo+i));
    }
    printf("\n");
}
