#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *pont_arq;
  int c;
  int count;
      
  pont_arq = fopen("teste.txt","r");
  
  printf("Lendo e exibindo os dados do arquivo \n\n");
  //Faça 
  do
  {  
      //faz a leitura do caracter no arquivo apontado por pont_arq
      c = fgetc(pont_arq);
      count++;
      
      //exibe o caracter lido na tela
      printf("%c" , c);        
  }while (c != EOF);//enquanto não for final de arquivo 
  
  fclose(pont_arq);//fechando o arquivo
  printf("\n%d\n",count);
  //system("pause");//pausa na tela, somente para Windows
  return 0;
}