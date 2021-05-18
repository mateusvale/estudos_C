#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
  FILE *pont_arq;
  int count, contador, c, config;
  count = contador = 0;
  config = 2;
  int flag_wall = FALSE;
  char array[100];
  
  //o numero de * é o mesmo - 20 para o 1 e 24 para o 2
  //42 caracteres no 1 e 56 no 2
  //contando com os pula linha, temos no primeiro 62 e no segundo
      
  pont_arq = fopen("teste.txt","r");
  
  //Faça 
  do
  {  
      c = fgetc(pont_arq);

      if (config == 1){
        if (c == '*'){
          flag_wall = TRUE;
        }
        if (flag_wall == TRUE && count < 48){
          array[count++] = c;
        }
      }

      else{
        if (c == '*' && contador > 20){
          flag_wall = TRUE;
        }
        if (flag_wall == TRUE && count < 59){
          array[count++] = c;
        }
      }

      if (c =='*')contador++;
      
  }while (c != EOF);
  
  fclose(pont_arq);//fechando o arquivo

  printf("%d\n", count);

  for (int i= 0; i < 59; i++){
    if (array[i] != '\n'){
      printf("%c",array[i]);
    }
  }

  printf("\n");

  return 0;
}