#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

void remove_espacos (char string[]);

int main(){
    int c;

    int primeira_escolha = FALSE;
    int proxima_escolha = FALSE;
    // int *resposta, resp;
    // resposta = &resp;
    char comando_c[1000];
    int count = 0;
    

    while (TRUE == 1){

        while ((c = getchar()) != '\n'){
            comando_c[count++] = c;
        }
        comando_c[count] = '\0';
        count = 0;
        // printf("%c\n",comando_c[count]);
        
        // comando_c[]
        if (proxima_escolha == TRUE){
            if (comando_c[0] == '1'){
                printf("\nConfiguração utilizada: %d\n", comando_c[1]);
            }
            else{
                printf("\nConfiguração permanecida\n");
            }
            
            proxima_escolha = FALSE;
        }

        else if (comando_c[0] == 'l' &&  comando_c[1] == '\0'){
            //lista()
            remove_espacos(comando_c);
            printf("Listagem de opções\n");
            continue;
        }
        else if (comando_c[0] == 'c' && primeira_escolha == FALSE){
            primeira_escolha = TRUE;
            remove_espacos(comando_c);
            printf("Configuração utilizada: %c\n", comando_c[1]);
            continue;
        }

        else if (comando_c[0] == 'c' && primeira_escolha == TRUE){
            remove_espacos(comando_c);
            printf("Quer realmente fazer isso? Digite 1 para sim ou 0 para não: ");
            proxima_escolha = TRUE;
        }

        else if ((comando_c[0] == 'm' || comando_c[0] == 'p') && primeira_escolha == FALSE){
            printf("Escolha primeiro a configuração desejada\n");
            continue;
        }
        else if (comando_c[0] == 'm' && primeira_escolha == TRUE){
            remove_espacos(comando_c);
            printf("x = %d\ny = %d\nDireção: %c\n", comando_c[1], comando_c[2],comando_c[3]);
            continue;
        }

        else if (comando_c[0] == 'p' && primeira_escolha == TRUE){
            remove_espacos(comando_c);
            //imprime
            printf("imprime os movimentos");
            continue;
        }
        else {
            printf("Opção inválida!\nAs opções possíveis são:\n\t- l\n\t- c <n>\n\t- m <linha> <coluna> <direção>\n\t- p\n");
        }
        
    }
    
}


void remove_espacos (char string[]){
    int i = 0, j = 0;
    char aux[100];
    while (string[i] != '\0'){
        if (string[i] != ' ' && string[i] != '\t'){
            aux[j++] = string[i]; 
        }
        i++;
    }
    aux[j] = '\0';
    // for (int w = 0; aux[w] != '\0'; i++){
    //     string[w] = aux[w];
    // }
    j = 0;
    while(aux[j] != '\0'){
        string[j] = aux[j];
        j++;
    }
    string[j] = '\0';
}