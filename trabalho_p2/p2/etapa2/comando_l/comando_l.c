#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

void comando_l (char *nome_arquivo);

char *nome_txt(int argc, char *argv[]); //funcionando

int *leitura (char *nome_arquivo, int config); //funcionando

int main (int argc, char *argv[]){

    //######################coleta do nome no parametro######################//
    char *nome_arquivo;
    nome_arquivo = nome_txt(argc,argv);
    // for (int i= 0; *(nome_arquivo+i) != '\0'; i++)printf("%c",*(nome_arquivo+i));
    // printf("\n");
    //######################coleta do nome no parametro######################//

    // int i = 40;
    // printf("%d\n", (i+2)/7);
    // if ((i+2)/7 < 6)printf("opa\n");

    //######################coleta do local das pecas######################//
    int config = 1;
    int *pecas = leitura (nome_arquivo, config);
    for (int i = 0; *(pecas+i) != '\0'; i++) printf("%c",*(pecas+i));
    printf("\n");
    //######################coleta do local das pecas######################//
    
    comando_l(nome_arquivo);
   
    
    return 0;
}

char *nome_txt(int argc, char *argv[]){

    int c,count_letter, anterior, flag_name, contem_f;
    flag_name = contem_f = FALSE;
    count_letter = anterior = 0;
    static char nome_arquivo_array[50];
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
    char *p;
    if (contem_f == FALSE){
        static char novo_nome[] = "haikori.txt";
        p = novo_nome;
    }else{
        p = nome_arquivo_array;
    }
    return p;
}

int *leitura (char *nome_arquivo, int config){

  FILE *pont_arq;
  int count = 0, contador = 0, c;
  int flag_wall = FALSE;
  static int array[100];
  
      
  pont_arq = fopen(nome_arquivo,"r");
  
  do
  {  
      c = fgetc(pont_arq);
      if (config == 1){
        if (c == '*') flag_wall = TRUE;
        if (flag_wall == TRUE && count < 42 && c != '\n') array[count++] = c;
      }
      else{
        if (c == '*' && contador > 20) flag_wall = TRUE;
        if (flag_wall == TRUE && count < 55 && c != '\n') array[count++] = c;
      }
      if (c =='*')contador++;
  }while (c != EOF);
  
  fclose(pont_arq);//fechando o arquivo

  array[count] = '\0';

  int *p = array;

  return p;
}

void comando_l (char *nome_arquivo){
    int *config1 = leitura (nome_arquivo, 1);
    int *config2 = leitura (nome_arquivo, 2);

    printf("1\n");
    printf("Floco de Neve\n");
    printf("  1234\n");

    int i = 0;
    for (;*(config1+i) != '\0'; i++){
        if (i == 0){
            printf(" %c",*config1);
        }
        else if ((i+1)%6 == 0){
            if ((i+2)/7 < 6){
                printf("%c\n%d",*(config1+i),(i+2)/7);
            } else{
                printf("%c\n",*(config1+i));
            }
        }else printf("%c",*(config1+i));
    }
}

