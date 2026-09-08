//v4
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#include "V4_AndreLuis_ErikSoares_RafaelCosta_RobertoAlves.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    Pessoa *pessoas = NULL;
    int quant = 0;
    int opcao = -1;
    int capacidade = 0;
    int posicaoPessoa;

    while (capacidade <= 0) {
        printf("Qual sera a capacidade maxima de pessoas permitidas a se cadastrar? ");
        if (scanf("%d", &capacidade) != 1 || capacidade <= 0) {
            printf("Valor invalido! Digite um numero positivo.\n");
            while (getchar() != '\n');
        }
    }

    pessoas = (Pessoa *) malloc(capacidade * sizeof(Pessoa));
    if (pessoas == NULL) {
        printf("Erro: falha ao alocar memoria para pessoas!\n");
        return 1;
    }

    while (opcao != 0) {
        formt(5);
        moldura();
        printf("        SISTEMA DE AFINIDADES\n");
        moldura();
        formt(1);
        opcoes();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');
        formt(1);

        switch (opcao) {
            case 1:
                CadastrarPessoas(pessoas, &quant, capacidade);
                break;

            case 2:
                // Exibir pessoas e preferências
                ExibirPessoas(pessoas, quant);
                break;

            case 3:
                posicaoPessoa = BuscaPessoa(pessoas, quant);
                if (posicaoPessoa == -1) {
                    printf("Pessoa não encontrada.\n");
                } else {
                    printf("%s encontrada na posição: %d\n", pessoas[posicaoPessoa].nome, posicaoPessoa);
                }
                formt(10);
                break;

            case 4:
                CompararDuasPessoas(pessoas, quant);
                break;

            case 5:
                // Encontrar pessoa mais semelhante
                EncontrarMaisSemelhante(pessoas, quant);
                break;

            case 6:
                // Exibir ranking de afinidade
                ExibirRankingAfinidade(pessoas, quant);
                break;

            case 7:
                // Analisar preferências de duas pessoas
                AnalisarPreferencias(pessoas, quant);
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

    free(pessoas);
    pessoas = NULL;

    return 0;
}