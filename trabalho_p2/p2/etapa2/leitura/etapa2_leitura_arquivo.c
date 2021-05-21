#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


int *configuracao (char nome_arquivo[], int config);

int main(void){

  char name[] = "teste.txt";  
  int config = 1;

  // int elements = 100;

  int *pointer = configuracao (name, config);

  // pointer = (int *) malloc(elements * sizeof(int));

  // pointer 

  for (int i = 0; *(pointer+i) != '\0'; i++) printf("%c",*(pointer+i));

  printf("\n");

  return 0;
}



int *configuracao (char nome_arquivo[], int config){

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

  // int i= 0;
  // for (; array[i] != '\0'; i++){
  //     printf("%c",array[i]);
  // }
  // printf("\n");

  return p;

  

}