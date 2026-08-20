//v1
//André Luís Paiva
//Roberto Alves Antunes
//Rafael Costa Oliveira
#include "func.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


#define MAX_PESSOAS 30
#define QUANT_ESC 6
#define TAM_NOME 50


//cabeçalhos aq
float LerNotaValida(void);
int buscaPessoa(char nomes[][TAM_NOME], int quant, const char *nomeProcurado);
float CalcularDistancia(float notas[][QUANT_ESC], int pont1, int pont2);
void CadastrarPessoas(char nomes[][TAM_NOME], float notas[][QUANT_ESC], int *quant);



void moldura() { printf("========================================"); }
void opcoes() {
  printf("1 - Cadastrar Pessoas\n");
  printf("2 - Exibir pessoas e preferências\n");
  printf("3 - Buscar pessoa pelo nome\n");
  printf("4 - Comparar duas pessoas");
  printf("5 - Encontrar pessoa mais semelhante\n");
  printf("6 - Exibir ranking de afinidade\n");
  printf("7 - Analisar preferências de duas pesssoas\n");
  printf("0 - Encerrar\n");
}

void formt(int q) {
  int i;
  for (i = 1; i <= q; i++) {
    printf("\n");
  }
}


void CadastrarPessoas(char nomes[][TAM_NOME], float notas[][QUANT_ESC], int *quant) {
  int novos, valido = 0;
  while(!valido) {
  printf("Quantas pessoas deseja cadastrar: ");
  scanf("%d", &novos);
  if(novos <= 0 || *quant + novos > MAX_PESSOAS){
    printf("Quantidade acima do Limite permitido, insira um número menor!");
  }
  else {valido = 1;}
}
  for(int j = *quant; j < *quant + novos; j++) {
    printf("Digite o nome da pessoa: ");
    scanf("%49[^\n]", nomes[j]);
    for(int k = 0; k < QUANT_ESC; k++) {
      printf("Digite a nota para a preferencia %d: ", k + 1);
      notas[j][k] = LerNotaValida();
    }
  }
  *quant = *quant + novos;
}


float LerNotaValida() {
  float nota;
  while(1) { //loopzinho de invalidez
    if(scanf("%f", &nota) == 1 && nota >= 0.0f && nota <= 10.0f) { //validação da nota
      return nota;
    }
    printf("Nota invalida! Digite um valor entre 0 e 10: ");
    while(getchar() != '\n'); //garantia pra caso algum valor estranho sobrar
  }
}


int BuscaPessoa(char nomes[][TAM_NOME], int quant, char nomebuscando[]) {
  for(int i = 0; i < quant; i++) { //correndo a matriz
    if(strcmp(nomes[i], nomebuscando) == 0) { //dos criadores de procurando NEMO, procurando o NOME
      return i; //achou a posição do nome!!
    }
  }
  return -1; //n achou
}


float CalcularDistancia(float notas[][QUANT_ESC], int pont1, int pont2) {
  float soma = 0;
  for(int j = 0; j < QUANT_ESC; j++) {
    float diff = notas[pont1][j] - notas[pont2][j];
    soma = soma + (diff * diff);
  }

  return sqrt(soma);
}