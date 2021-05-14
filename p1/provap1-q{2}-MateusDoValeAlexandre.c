#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_ELEMENTOS 1000
#define TRUE 1
#define FALSE 0

//#######################################################################//

void separa_inteiro(int entrada_int[], char entrada[], int tamanho);

void verifica_numeros(int entrada_int[], int distintos_e_entre1e60[]);

void ordenar(int entrada_int[], int len);

int entrada_teclado(int tamanho ,char entrada[]);

void randomico_distinto_ordenado(int sena[]);

int compara (int entrada_int[], int sena[]);

void tempo(int semanas);

//#######################################################################//

int main(void){
    int num;

    int entrada_int[6];

    char entrada[MAX_ELEMENTOS];

    int distintos_e_entre1e60[] = {TRUE,TRUE};

    int sena[6]; 

    srand(time(NULL));

    //recebe a entrada
    num = entrada_teclado(MAX_ELEMENTOS,entrada);
    
    //verificação se tem 6 numeros
    if (num != 6){
        if (num < 6) {
            printf("Faltou %d número(s)\n", 6 - num);
        } else{
            printf("Você entrou com %d número(s) a mais\n", num - 6);
        }
    }
    else {

        int tamanho = strlen(entrada);
        separa_inteiro(entrada_int, entrada,tamanho);

        //Verificar se os numeros são distintos e de 1 a 60
        verifica_numeros(entrada_int, distintos_e_entre1e60);

        if (distintos_e_entre1e60[0] == FALSE && distintos_e_entre1e60[1] == FALSE){
            printf("Numeros devem ser de 1 a 60\n");
            printf("Existem números repetidos\n");
        } else
            
        if (distintos_e_entre1e60[0] == FALSE && distintos_e_entre1e60[1] == TRUE){
            printf("Existem números repetidos\n");
        } else

        if (distintos_e_entre1e60[0] == TRUE && distintos_e_entre1e60[1] == FALSE){
            printf("Numeros devem ser de 1 a 60\n");
        } 
        
        //#######################################################################//

        else{

            ordenar(entrada_int, 6);
            randomico_distinto_ordenado(sena);

            //#############################################################//

            int num_iguais = 0,quant_gerados,semanas;
            float custo = 4.5;
            quant_gerados = semanas = 1;

            printf("##########################\n");

            while((num_iguais = compara(entrada_int, sena)) != 6){
                
                if (num_iguais == 4){
                    printf("QUADRA!! - %d números acertados\n", num_iguais);
                    printf(" - Foram gerados %d sorteios\n", quant_gerados);
                    printf(" - O custo até agora foi de R$%.1f\n", custo);
                    tempo(semanas);
                    printf("##########################\n");
                }

                if (num_iguais == 5){
                    printf("QUINA!! - %d números acertados\n", num_iguais);
                    printf(" - Foram gerados %d sorteios\n", quant_gerados);
                    printf(" - O custo até agora foi de R$%.1f\n", custo);
                    tempo(semanas);
                    printf("##########################\n");
                }

                custo += 4.5;
                quant_gerados++;

                 if (quant_gerados % 2 == 1){
                    semanas++;
                }
                randomico_distinto_ordenado(sena);
            }

            //#############################################################//
            printf("\n                ###########PARABÉNS###########");
            printf("\n - Você é o novo ganhador da Mega-Sena!!!!! Acertou os %d números\n", num_iguais);
            printf(" - Foram gerados %d sorteios\n", quant_gerados);
            printf(" - O custo total foi de R$%.1f\n", custo);
            tempo(semanas);

        }
    }
    printf("\n");
    
    return 0;
}

//#######################################################################//

//AREA DE FUNCOES:

//#######################################################################//
//Entrada do teclado
int entrada_teclado(int tamanho ,char entrada[]){
    int len, num, c;
    num = 1;
    for (len=0; len < tamanho - 1  && (c=getchar()) != EOF && c!='\n'; ++len){
        entrada[len] = c;
        if (entrada[len] == ' '){
            num++;
        }
    }
    entrada[len] = '\0';
    return num;
}

//#######################################################################//
//verifica se os numeros sao distintos e maiores que 1 e menores que 60
void verifica_numeros(int entrada_int[], int distintos_e_entre1e60[]){
    int igual;
    for (int i = 0; i <= 5; i++){
            igual = 0;
            if (entrada_int[i] < 1 || entrada_int[i] > 60){
                distintos_e_entre1e60[1] = FALSE;
            }
            for (int j = 0; j <= 5; j++){
                if (entrada_int[i] == entrada_int[j]){
                    igual++;
                }
            }
            if (igual > 1){
                distintos_e_entre1e60[0] = FALSE;
            }
    }
}

//#######################################################################//
//ordena o vetor
void ordenar(int entrada_int[], int len){
    int k, j, auxiliar;
    for (k = len - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            if (entrada_int[j] > entrada_int[j + 1]) {
                auxiliar = entrada_int[j];
                entrada_int[j] = entrada_int[j + 1];
                entrada_int[j + 1] = auxiliar;
            }
        }
    }
}

//#######################################################################//
//verifica se o array te elementos distintos
int distintos (int array[]){
    int igual;
    int resultado = TRUE;
    for (int i = 0; i <= 5; i++){
            igual = 0;
            for (int j = 0; j <= 5; j++){
                if (array[i] == array[j]){
                    igual++;
                }
            }
            if (igual > 1){
                resultado = FALSE;
            }
    }
    return resultado;
}

//#######################################################################//
//gera um randomico distinto
void randomico_distinto_ordenado(int sena[]){
    int i;
    do {
        for(i=0 ; i < 6 ; i++){
            sena[i] = rand() % (60 +1 - 1) +1;
        }
    }
    while(distintos(sena) == FALSE);     

    ordenar(sena,6);    
}

//#######################################################################//
//compara a entrada com o valor da sena e retorna a quantidade de numeros iguais:
int compara (int entrada_int[], int sena[]){
    int count = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (entrada_int[j] == sena[i]){
                count++;
            }
        }
    }
    return count;
}

//#######################################################################//
//print o valor de anos, meses e semanas
void tempo(int semanas){
    int ano, mes, semana;
    
    ano = semanas / 54;
    semana = semanas % 54;
    mes = semana / 4;
    printf(" - O tempo foi de %d ano(s), %d mes(es) e %d semanas\n", ano, mes, semana%4);
}

//#######################################################################//
//transforma os elementos string de um vetor, transforma-os em int e depois adiciona em outro vetor
void separa_inteiro(int entrada_int[], char entrada[], int tamanho){
    int i, j, valor, w;
    i = j = valor = w =0;
    char aux[tamanho];
    int count = 0;
    for (; entrada[i] != '\0'; i++){
        count++;
        if (entrada[i] != ' '){
            aux[j++] = entrada[i];
        }
        else{
            aux[j] = '\0';
            entrada_int[w++] = atoi(aux);
            j = 0;
        }
    }
    if (count == tamanho){
            aux[j] = '\0';
            entrada_int[w++] = atoi(aux);
        }
}