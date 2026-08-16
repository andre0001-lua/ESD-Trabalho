//v1
//André Luís Paiva
//Roberto Alves Antunes
//Rafael Costa Oliveira
#include "func.h"
#include <stdio.h>

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
