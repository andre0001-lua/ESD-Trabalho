//v1
//André Luís Paiva
//Roberto Alves Antunes
//Rafael Costa Oliveira
#include "func.h"
#include <stdio.h>
int main() {
  char nomes[MAX_PESSOAS][TAM_NOME];
  float notas[MAX_PESSOAS][QTD_PREF];
  int quant = 0;

  menu(nomes, notas, &quant);

  return 0;
}
