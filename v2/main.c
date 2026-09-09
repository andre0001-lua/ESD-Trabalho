//v2
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#include "V2_AndreLuis_ErikSoares_RafaelCosta_RobertoAlves.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    float *notas = NULL;
    char (*nomes)[TAM_NOME] = NULL;
    
    int quant = 0;
    int menu = -1;
    int posicaoPessoa;
    int capacidade = 0;


    while (capacidade <= 0) {
        printf("Qual sera a capacidade maxima de pessoas permitidas a se cadastrar? ");
        if (scanf("%d", &capacidade) != 1 || capacidade <= 0) {
            printf("Valor invalido! Digite um numero positivo.\n");
            while (getchar() != '\n');
        }
    }

    // Alocação dinâmica de notas e nomes
    notas = (float *) malloc(capacidade * QTD_PREF * sizeof(float));
    nomes = malloc(capacidade * sizeof(*nomes));

    if (notas == NULL || nomes == NULL) {
        printf("Erro: falha ao alocar memoria!\n");
        if (notas != NULL) free(notas);
        if (nomes != NULL) free(nomes);
        return 1;
    }

    while (menu) {
        moldura();
        printf("        SISTEMA DE AFINIDADES\n");
        moldura();
        formt(1);
        opcoes();
        printf("Digite a opção desejada: ");
        scanf("%d", &menu);
        while (getchar() != '\n');   
        formt(1);

        switch (menu) {
            case 1:
                CadastrarPessoas(nomes, notas, &quant, capacidade);
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
                AnalisarPreferencias(nomes, notas, quant);
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                formt(10);
                break;
        }   
    }

    free(notas);
    free(nomes);
    notas = NULL;
    nomes = NULL;

  return 0;
}