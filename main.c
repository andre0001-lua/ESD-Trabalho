//v1
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#include "func.h"
#include <stdio.h>

int main() {
  
  char nomes[MAX_PESSOAS][TAM_NOME];
  float notas[MAX_PESSOAS][QTD_PREF];
  int quant = 0;
  int menu = -1;
  int posicaoPessoa;

    while (menu) {
        moldura();
        printf("        SISTEMA DE AFINIDADES\n");
        moldura();
        formt(1);
        opcoes();
        printf("Digite a opção desejada: ");
        scanf("%d", &menu);
        formt(1);

        switch (menu) {
            case 1:
                CadastrarPessoas(nomes, notas, &quant);
                break;

            case 2:
                // Exibir pessoas e preferências
                ExibirPessoas(nomes, notas, quant);
                break;

            case 3:
                posicaoPessoa = BuscaPessoa(nomes, quant);
                if (posicaoPessoa == -1) {
                    printf("Pessoa não encontrada.\n");
                } else {
                    printf("%s encontrada na posição: %d\n", nomes[posicaoPessoa], posicaoPessoa);
                }
                formt(10);
                break;

            case 4:
                CompararDuasPessoas(nomes, notas, quant);
                break;

            case 5:
                // Encontrar pessoa mais semelhante
                EncontrarMaisSemelhante(nomes, notas, quant);
                break;

            case 6:
                // Exibir ranking de afinidade
                ExibirRankingAfinidade(nomes, notas, quant);
                break;

            case 7:
                // Analisar preferências de duas pessoas
                formt(10);
                break;

            case 0:
                printf("Saindo do programa...\n");
                menu = 0;
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                formt(10);
                break;
        }   
    }

  return 0;
}
