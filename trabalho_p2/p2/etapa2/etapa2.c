#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

void guarda_movimentos(int **movimentos, int movimento, char comandos[]);

void remove_espacos (char string[]);

int *quantpecas_localidade (int *campo, int peca, int mx, int my);

int verifica_movimentacao (int *campo, int x, int y, char direcao, int configuracao);

void imprime(int *peca, int configuracao); //funcionando

void comando_l (char *nome_arquivo); //funcionando

char *nome_txt(int argc, char *argv[]); //funcionando

int *leitura (char *nome_arquivo, int config); //funcionando

void movimentacao (int *campo, int x, int y, char direcao, int configuracao);

void traducao_direcao(char direcao);

int main (int argc, char *argv[]){

    char *nome_arquivo;
    nome_arquivo = nome_txt(argc,argv);
    int *pecas;
    //int *pecas_original;
    int **movimentos = (int **) (malloc(3*sizeof(int *))); //nao uso movimentos[0]
    for (int i = 0; i < 3; i++ ){
        movimentos[i] = (int *) malloc(3 * sizeof(int));
    }
    int c, config;

    int primeira_escolha = FALSE;
    int proxima_escolha = FALSE;
    
    int movimento = 0;
    char comandos[50];
    int countador_comandos = 0;

    while (TRUE == 1){

        while ((c = getchar()) != '\n'){
            comandos[countador_comandos++] = c;
        }
        comandos[countador_comandos] = '\0';
        countador_comandos = 0;
        // printf("%c\n",comandos[count]);
        
        // comandos[]
        if (proxima_escolha == TRUE){ //finalizado
            if (comandos[0] == '1'){
                config = (config + 1 == 3) ? 1 : 2;
                pecas = leitura (nome_arquivo, config);
                // *pecas_original = *pecas;
                printf("\n");
                imprime(pecas,config);
                movimento = 0;
                // printf("\nConfiguração utilizada: %d\n", comandos[1]);
                //zerar os ponteiros que movimentaram
            }
            else{
                printf("\nConfiguração permanecida\n\n");
            }
            proxima_escolha = FALSE;
        }

        else if (comandos[0] == 'l' &&  comandos[1] == '\0'){ //comando_l -> feito
            //lista()
            printf("\n");
            remove_espacos(comandos);
            //printf("Listagem de opções\n");
            comando_l(nome_arquivo);

            continue;
        }

        else if (comandos[0] == 'c' && primeira_escolha == FALSE){ //primeiro comandos -> feito
            primeira_escolha = TRUE;
            remove_espacos(comandos);
            config = comandos[1] - '0';
            pecas = leitura (nome_arquivo, config);
            // *pecas_original = *pecas;
            imprime(pecas,config);
        }

        else if (comandos[0] == 'c' && primeira_escolha == TRUE){ //mudanca de configuracao - pergunta ->feito
            remove_espacos(comandos);
            // printf("config: %d\ncomando[1]: %d\n",config,comandos[1]);
            if (config == (comandos[1] - '0')){
                printf("Configuração permanecida\n\n");
            }
            else{
                printf("Quer realmente fazer isso? Digite 1 para sim ou 0 para não: ");
                // mudanca_configuracao_igual = (config == comandos[1])?
                proxima_escolha = TRUE;
            }
        }

        else if ((comandos[0] == 'm' || comandos[0] == 'p') && primeira_escolha == FALSE){//feito
            printf("Escolha primeiro a configuração desejada\n\n");
            continue;
        }

        else if (comandos[0] == 'm' && primeira_escolha == TRUE){//comando_m -> feito
            remove_espacos(comandos);
            if (verifica_movimentacao(pecas, comandos[1] - '0', comandos[2] - '0', comandos[3], config) == TRUE){
                movimento++;
                printf("Movimento %d\n", movimento);
                guarda_movimentos(movimentos, movimento, comandos);
            }

            movimentacao (pecas, comandos[1] - '0', comandos[2] - '0', comandos[3], config);
            //printf("x = %d\ny = %d\nDireção: %c\n", comandos[1], comandos[2],comandos[3]);
            continue;
        }

        else if (comandos[0] == 'p' && primeira_escolha == TRUE){
            remove_espacos(comandos);
            // imprime(pecas_original,config);
            for (int i = 1; i <= movimento;i++){
                printf("\n");
                // movimentacao(pecas_original,movimentos[movimento][0],movimentos[movimento][1],movimentos[movimento][2],config)
            }            
            printf("\n");
            continue;
        }
        else {
            printf("Opção inválida!\nAs opções possíveis são:\n\t- l\n\t- c <n>\n\t- m <linha> <coluna> <direção>\n\t- p\n\n");
        }
        
    }

    return 0;
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
        if (c == '*' && contador >= 20) flag_wall = TRUE;
        if (flag_wall == TRUE && count < 56 && c != '\n') array[count++] = c;
      }
      if (c =='*')contador++;
  }while (c != EOF);
  
  fclose(pont_arq);//fechando o arquivo

  array[count] = '\0';

  int *p = array;

  return p;
}

void comando_l (char *nome_arquivo){
    int *config1;// = leitura (nome_arquivo, 1);
    int *config2;// = leitura (nome_arquivo, 2);
    printf("1\nFloco de Neve\n");
    config1 = leitura (nome_arquivo, 1);
    imprime(config1, 1);
    printf("2\nEngarrafamanto\n");
    config2 = leitura (nome_arquivo, 2);
    imprime(config2, 2);
}

void imprime(int *peca, int configuracao){
    int coluna = 1;
    int mx = (configuracao == 1) ? 6 : 8;
    if (configuracao == 1) printf("  1234\n");
    if (configuracao == 2) printf("  123456\n");
    for (int i = 0;*(peca+i) != '\0'; i++){
        if (i == 0){
            printf(" %c",*peca);
        }
        else if ((i+1)%mx == 0){
            if (coluna < 6){
                printf("%c\n%d",*(peca+i),coluna++);
            } else{
                printf("%c\n ",*(peca+i));
            }
        }else printf("%c",*(peca+i));
    }
    printf("\n");
}

void traducao_direcao(char direcao){
    switch (direcao){
    case 'B':
        printf("baixo\n");
        break;
    case 'T':
        printf("topo\n");
        break;
    case 'E':
        printf("esquerda\n");
        break;
    case 'D':
        printf("direita\n");
        break;      
    default:
        printf("nenhum lugar\n");
    }
}

int *quantpecas_localidade (int *campo, int peca, int mx, int my){
    int total = mx*my, i = 0, count = 0, *count_e_localidade;
    static int arr1[30]; //numero alto para ser maior do que a quantidade de '*'
    for (;i <= total; i++){
        if (*(campo+i) == peca){
            arr1[count++] = i;
        }
    }
    arr1[count] = 's';
    static int arr2[30];
    arr2[0] = count;
    for (int j = 0;arr1[j] != 's'; j++){
        arr2[j+1] = arr1[j];
    }
    count_e_localidade = arr2;
    return count_e_localidade;
}

int verifica_movimentacao (int *campo, int x, int y, char direcao, int configuracao){
    int mx = 7;
    int my = (configuracao == 1) ? 6 : 8;

    if (x > mx || y > my){
        return FALSE;
    }
    int local_peca = my*y + x;
    int peca = *(campo+local_peca);
    int *count_e_localidade;
    count_e_localidade = quantpecas_localidade(campo, peca, mx, my); //(count,x,x,x,x)
    int quantidade = *count_e_localidade;
    int peca_vazia = 0, peca_mesma = 0;
    //Para o movimento da peca for valido, quando houver a movimentacao,
    //metade de seu corpo irá para o vazio e a outra metade irá para o lugar que era sua peca 
    //a afirmacao acima é só quando a peca tem 4 ou 2 tamanhos, pois caso seja 1 tamanho, ele vai direto para o vazio
    //T B E D
    if (peca != ' ' || peca != '*' || peca != '+'){
        if (direcao == 'D'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)+1 )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)+1 )) == peca){
                    peca_mesma++;
                }
            }
        }
        else if (direcao == 'E'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)-1 )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)-1 )) == peca){
                    peca_mesma++;
                }
            }
        }
        else if (direcao == 'B'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)+my )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)+my )) == peca){
                    peca_mesma++;
                }
            }
        } else if(direcao == 'T'){
            for (int i = 0; i < quantidade; i++){
                if ( *(campo+( *(count_e_localidade+1+i)-my )) == ' '){ //soma a peca em 1
                    peca_vazia++;
                }
                else if (*(campo+( *(count_e_localidade+1+i)-my )) == peca){
                    peca_mesma++;
                }
            }
        } else return FALSE;
    }
        else{
            return FALSE;
        }
    if (quantidade == 4 && peca_vazia == 2 && peca_mesma ==2){
        return TRUE;
    } //colocar 3 pecas aqui por conta do tabuleiro 2
    else if(quantidade == 3 && peca_vazia == 2 && peca_mesma == 1){
        return TRUE;
    }
    else if ((quantidade == 2 && peca_vazia == 1 && peca_mesma == 1) || (quantidade == 2 && peca_vazia == 2 && peca_mesma == 0)){
        return TRUE;
    }
    else if (quantidade == 1 && peca_vazia == 1 && peca_mesma ==0){
        return TRUE;
    } else return FALSE;

}

void movimentacao (int *campo, int x, int y, char direcao, int configuracao){
    int mx = 7;
    int my = (configuracao == 1) ? 6 : 8;
    if (verifica_movimentacao(campo,x,y,direcao, configuracao) == 0){

        printf("\nImpossível movimentar peça em %d,%d para ", x,y);
        traducao_direcao(direcao);
        printf("\n");
    }
    else{
        int local_peca = my*y + x;
        int peca = *(campo+local_peca);
        int *count_e_localidade;
        count_e_localidade = quantpecas_localidade(campo, peca, mx, my); //(count,x,x,x,x)
        int quantidade = *count_e_localidade;
        int aux[quantidade];

        if (direcao == 'D'){
            for (int i = 0; i < quantidade; i++){
                *(campo+( *(count_e_localidade+1+i)+1)) = peca;
                aux[i] = *(count_e_localidade+1+i)+1;
            }
        }
        else if (direcao == 'E'){
            for (int i = 0; i < quantidade; i++){
                *(campo+( *(count_e_localidade+1+i)-1)) = peca;
                aux[i] = *(count_e_localidade+1+i)-1;
            }
            
        }
        else if (direcao == 'B'){
            for (int i = 0; i < quantidade; i++){
                *(campo+( *(count_e_localidade+1+i)+my)) = peca;
                aux[i] = *(count_e_localidade+1+i)+my;
            }
        } else {
            for (int i = 0; i < quantidade; i++){

                *(campo+( *(count_e_localidade+1+i)-my)) = peca;
                aux[i] = *(count_e_localidade+1+i)-my;
            }
        }
        int pode_apagar; 
        for (int i = 0; i < quantidade; i++){
            pode_apagar = TRUE; 
            for (int j = 0; j < quantidade; j++){
                if(*(count_e_localidade+1+i) == aux[j]){
                    pode_apagar = FALSE;
                    break;
                }
            }
            if (pode_apagar == TRUE){
                *(campo+( *(count_e_localidade+1+i))) = ' ';
            }    
        }
        imprime(campo, configuracao);
        //printMatriz (campo,mx,my);
    }
}

void guarda_movimentos(int **movimentos, int movimento, char comandos[]){

    // if (movimento % 2 == 0){
    //         movimentos = (int **)realloc(movimentos,movimento*2*sizeof(int *));
    //         for (int j = movimento; j<=(movimento*2);j++){
    //             movimentos[j] = (int *) malloc(3 * sizeof(int));
    //         }
    // }

    if (movimento >= 3){
        movimentos = (int **)realloc(movimentos,++movimento*sizeof(int *));
        movimentos[--movimento] = (int *) malloc(3 * sizeof(int));
    }
    for (int i = 0; i < 3; i++){
        
        if (i != 2){
            movimentos[movimento][i] = comandos[i] - '0';
        }
        else{
            movimentos[movimento][i] = comandos[i];
        }
        
    }
}