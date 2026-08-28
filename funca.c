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

void menu(char nomes[][TAM_NOME], float notas[][QTD_PREF], int *quant) {
    int i = -1;
    int posicaoPessoa;

    while (i != 0) {
        moldura();
        printf("SISTEMA DE AFINIDADE");
        moldura();
        formt(1);
        moldura();
        opcoes();
        moldura();
        printf("Digite a opção desejada: ");
        scanf("%d", &i);
        formt(1);

        switch (i) {
            case 1:
                CadastrarPessoas(nomes, notas, quant);
                break;

            case 2:
                // Exibir pessoas e preferências
                ExibirPessoas(nomes, notas, *quant);
                break;

            case 3:
                posicaoPessoa = BuscaPessoa(nomes, *quant);
                if (posicaoPessoa == -1) {
                    printf("Pessoa não encontrada.\n");
                } else {
                    printf("%s encontrada na posição: %d\n", nomes[posicaoPessoa], posicaoPessoa);
                }
                break;

            case 4:
                CompararDuasPessoas(nomes, notas, *quant);
                break;

            case 5:
                // Encontrar pessoa mais semelhante
                EncontrarMaisSemelhante(nomes, notas, *quant);
                break;

            case 6:
                // Exibir ranking de afinidade
                break;

            case 7:
                // Analisar preferências de duas pessoas
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }   
    }
}

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


void CadastrarPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int *quant) {
  int novos, valido = 0;
  while(!valido) {
  printf("Quantas pessoas deseja cadastrar: ");
  scanf("%d", &novos);
  if(novos <= 0 || *quant + novos > MAX_PESSOAS){
    printf("Quantidade acima do Limite permitido, insira um número menor!");
  }
  else {valido = 1;}
}

  while(getchar() != '\n');

  for(int j = *quant; j < *quant + novos; j++) {
    printf("Digite o nome da pessoa: ");
    scanf("%49[^\n]", nomes[j]);
    while(getchar() != '\n');
    for(int k = 0; k < QTD_PREF; k++) {
      printf("Digite a nota para a preferencia %d: ", k + 1);
      notas[j][k] = LerNotaValida();
    }
  }
  *quant = *quant + novos;
}

void ExibirPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant)
{
  if (quant == 0)
  {
    printf("Nenhuma pessoa cadastrada ainda.\n");
    return;
  }

  int maiorNome = 4;

  for (int i = 0; i < quant; i++)
  {
    int tam = strlen(nomes[i]);
    if (tam > maiorNome)
    {
      maiorNome = tam;
    }
  }

  moldura();
  formt(1);
  printf("%-*s %6s %6s %6s %6s %6s %6s\n", maiorNome, "NOME", "MUS", "CIN", "JOG", "ESP", "LEI", "PROG");
  moldura();
  formt(1);

  for (int i = 0; i < quant; i++)
  {
    printf("%-*s", maiorNome, nomes[i]);
    for (int j = 0; j < QTD_PREF; j++)
    {
      printf(" %6.1f", notas[i][j]);
    }
    printf("\n");
  }

  moldura();
  formt(1);

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


void CompararDuasPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant) {
    float dist;

    printf("Primeira pessoa\n");
    int pos1 = BuscaPessoa(nomes, quant);
    
    printf("Segunda pessoa\n");
    int pos2 = BuscaPessoa(nomes, quant);

    if (pos1 == -1 || pos2 == -1) {
        printf("Não foi possível comparar: uma ou ambas as pessoas não foram encontradas.\n");
        return;
    }

    dist = CalcularDistancia(notas, pos1, pos2);

    moldura();
    printf("COMPARAÇÃO DE PERFIS\n");
    moldura();
    formt(1);
    printf("%s X %s\n", nomes[pos1], nomes[pos2]);
    printf("Distância: %.2f\n", dist);
}

void EncontrarMaisSemelhante(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant)
{
  if (quant < 2)
  {
    printf ("É necessário ter pelo menos 2 pessoas cadastradas para essa busca.\n");
    return;
  }

  printf ("Pessoa de referência\n");
  int ref = BuscaPessoa(nomes, quant);

  if (ref == -1) 
  {
    printf ("Pessoa não encontrada.\n");
    return;
  }

  int maisSemelhante= -1;
  float menorDistancia = -1;

  moldura ();
  printf ("BUSCA DE PERFIS SEMELHANTES\n");
  moldura();
  formt(1);
  printf ("Pessoa de referencia: %s\n", nomes[ref]);
  formt(1);

  for (int i =0; i < quant; i++)
  {
    if (i == ref)
    {
      continue;
    }

    float dist = CalcularDistancia(notas, ref, i);
    printf ("Distância para %s: %.2f\n", nomes[i], dist);

    if (maisSemelhante == -1 || dist < menorDistancia)
    {
      maisSemelhante = i;
      menorDistancia = dist;
    }
  }

  formt(1);
  printf ("----------------------------------\n");
  printf ("PERFIL MAIS SEMELHANTE\n");
  printf ("----------------------------------\n");
  printf ("%s\n", nomes[maisSemelhante]);
  printf ("Distância: %.2f\n", menorDistancia);

}

int BuscaPessoa(char nomes[][TAM_NOME], int quant) {
    char nomebuscando[TAM_NOME];
    printf("Digite o nome que deseja buscar: ");
    scanf("%s", nomebuscando);
    
    for (int i = 0; i < quant; i++) {
        if (strcmp(nomes[i], nomebuscando) == 0) {
            return i;
        }
    }
    return -1;
}


float CalcularDistancia(float notas[][QTD_PREF], int pont1, int pont2) {
  float soma = 0;
  for(int j = 0; j < QTD_PREF; j++) {
    float diff = notas[pont1][j] - notas[pont2][j];
    soma = soma + (diff * diff);
  }

  return sqrt(soma);
}
