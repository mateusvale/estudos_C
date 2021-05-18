//Leitura de arquivo
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *pont_arq;
  char texto_str[100];
  int count = 0;
  char *p;
  
  pont_arq = fopen("teste.txt", "r");
  
  while(fgets(texto_str, 11, pont_arq) != NULL){
      
      count++;
      if (count == 1){
        p = texto_str;
      }

      // printf()
      printf("%s", texto_str);
  }
  
  printf("\n%d\n",count);
  //fechando o arquivo
  fclose(pont_arq);
  
  printf("p: %c\n", *(p+4));

//   getch();
  return(0);
}