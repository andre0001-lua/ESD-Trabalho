//v2
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "V2_AndreLuis_ErikSoares_RafaelCosta_RobertoAlves.h"

void moldura(void) {
    printf("========================================\n");
}

void opcoes(void) {
    printf("1 - Cadastrar Pessoas\n");
    printf("2 - Exibir pessoas e preferencias\n");
    printf("3 - Buscar pessoa pelo nome\n");
    printf("4 - Comparar duas pessoas\n");
    printf("5 - Encontrar pessoa mais semelhante\n");
    printf("6 - Exibir ranking de afinidade\n");
    printf("7 - Analisar preferencias de duas pessoas\n");
    printf("0 - Encerrar\n");
}

void formt(int q) {
    for (int i = 1; i <= q; i++) {
        printf("\n");
    }
}

float LerNotaValida(void) {
    float nota;
    while (1) {
        if (scanf("%f", &nota) == 1 && nota >= 0.0f && nota <= 10.0f) {
            return nota;
        }
        printf("Nota invalida! Digite um valor entre 0 e 10: ");
        while (getchar() != '\n');
    }
}

int BuscaPessoa(char (*nomes)[TAM_NOME], int quant) {
    if (quant == 0) {
        return -1;
    }

    char nomebuscando[TAM_NOME];
    while (getchar() != '\n');
    printf("Digite o nome que deseja buscar: ");
    scanf("%49[^\n]", nomebuscando);
    while (getchar() != '\n');

    for (int i = 0; i < quant; i++) {
        if (strcmp(nomes[i], nomebuscando) == 0) {
            return i;
        }
    }
    return -1;
}

float CalcularDistancia(float *notas, int pont1, int pont2) {
    float soma = 0.0f;
    for (int j = 0; j < QTD_PREF; j++) {
        float diff = notas[pont1 * QTD_PREF + j] - notas[pont2 * QTD_PREF + j];
        soma += (diff * diff);
    }
    return sqrt(soma);
}

void CadastrarPessoas(char (*nomes)[TAM_NOME], float *notas, int *quant, int capacidade) {
    int novos, valido = 0;

    if (*quant >= capacidade) {
        printf("Capacidade maxima de cadastros atingida (%d pessoas).\n", capacidade);
        formt(10);
        return;
    }

    while (!valido) {
        printf("Quantas pessoas deseja cadastrar (restam %d vagas): ", capacidade - *quant);
        if (scanf("%d", &novos) != 1 || novos <= 0 || *quant + novos > capacidade) {
            printf("Quantidade invalida! Digite um valor entre 1 e %d.\n", capacidade - *quant);
            while (getchar() != '\n');
        } else {
            valido = 1;
        }
    }

    while (getchar() != '\n');

    for (int j = *quant; j < *quant + novos; j++) {
        printf("Digite o nome da pessoa %d: ", j + 1);
        scanf("%49[^\n]", nomes[j]);
        while (getchar() != '\n');

        for (int k = 0; k < QTD_PREF; k++) {
            printf("Digite a nota para a preferencia %d: ", k + 1);
            notas[j * QTD_PREF + k] = LerNotaValida();
        }
        while (getchar() != '\n');
    }

    *quant += novos;
    formt(10);
}

void ExibirPessoas(char (*nomes)[TAM_NOME], float *notas, int quant) {
    if (quant == 0) {
        printf("Nenhuma pessoa cadastrada ainda.\n");
        formt(10);
        return;
    }

    int maiorNome = 4;
    for (int i = 0; i < quant; i++) {
        int tam = strlen(nomes[i]);
        if (tam > maiorNome) {
            maiorNome = tam;
        }
    }

    moldura();
    formt(1);
    printf("%-*s %6s %6s %6s %6s %6s %6s\n", maiorNome, "NOME", "MUS", "CIN", "JOG", "ESP", "LEI", "PROG");
    moldura();
    formt(1);

    for (int i = 0; i < quant; i++) {
        printf("%-*s", maiorNome, nomes[i]);
        for (int j = 0; j < QTD_PREF; j++) {
            printf(" %6.1f", notas[i * QTD_PREF + j]);
        }
        printf("\n");
    }

    moldura();
    formt(10);
}

void CompararDuasPessoas(char (*nomes)[TAM_NOME], float *notas, int quant) {
    if (quant < 2) {
        printf("E necessario ter pelo menos 2 pessoas cadastradas para essa comparacao.\n");
        formt(10);
        return;
    }

    printf("Primeira pessoa\n");
    int pos1 = BuscaPessoa(nomes, quant);

    printf("Segunda pessoa\n");
    int pos2 = BuscaPessoa(nomes, quant);

    if (pos1 == -1 || pos2 == -1) {
        printf("Nao foi possivel comparar: uma ou ambas as pessoas nao foram encontradas.\n");
        formt(10);
        return;
    }

    float dist = CalcularDistancia(notas, pos1, pos2);

    moldura();
    printf("COMPARACAO DE PERFIS\n");
    moldura();
    formt(1);
    printf("%s X %s\n", nomes[pos1], nomes[pos2]);
    printf("Distancia: %.2f\n", dist);
    formt(10);
}

void EncontrarMaisSemelhante(char (*nomes)[TAM_NOME], float *notas, int quant) {
    if (quant < 2) {
        printf("E necessario ter pelo menos 2 pessoas cadastradas para essa busca.\n");
        formt(10);
        return;
    }

    printf("Pessoa de referencia\n");
    int ref = BuscaPessoa(nomes, quant);

    if (ref == -1) {
        printf("Pessoa nao encontrada.\n");
        formt(10);
        return;
    }

    float *distancias = (float *) malloc(quant * sizeof(float));
    if (distancias == NULL) {
        printf("Erro de alocacao temporaria.\n");
        return;
    }

    float menorDistancia = -1.0f;

    moldura();
    printf("BUSCA DE PERFIS SEMELHANTES\n");
    moldura();
    formt(1);
    printf("Pessoa de referencia: %s\n", nomes[ref]);
    formt(1);

    for (int i = 0; i < quant; i++) {
        if (i == ref) continue;

        float dist = CalcularDistancia(notas, ref, i);
        distancias[i] = dist;
        printf("Distancia para %s: %.2f\n", nomes[i], dist);

        if (menorDistancia < 0 || dist < menorDistancia) {
            menorDistancia = dist;
        }
    }

    formt(1);
    printf("----------------------------------\n");
    printf("PERFIL MAIS SEMELHANTE\n");
    printf("----------------------------------\n");

    for (int i = 0; i < quant; i++) {
        if (i == ref) continue;

        if (fabs(distancias[i] - menorDistancia) < 0.0001f) {
            printf("%s\n", nomes[i]);
        }
    }

    printf("Distancia: %.2f\n", menorDistancia);
    free(distancias);
    formt(10);
}

void ExibirRankingAfinidade(char (*nomes)[TAM_NOME], float *notas, int quant) {
    if (quant < 2) {
        printf("E necessario ter pelo menos 2 pessoas cadastradas para essa busca.\n");
        formt(10);
        return;
    }

    printf("Pessoa de referencia\n");
    int ref = BuscaPessoa(nomes, quant);

    if (ref == -1) {
        printf("Pessoa nao encontrada.\n");
        formt(10);
        return;
    }

    float *distancias = (float *) malloc((quant - 1) * sizeof(float));
    int *indices = (int *) malloc((quant - 1) * sizeof(int));

    if (distancias == NULL || indices == NULL) {
        printf("Erro de alocacao temporaria.\n");
        if (distancias != NULL) free(distancias);
        if (indices != NULL) free(indices);
        return;
    }

    int total = 0;
    for (int i = 0; i < quant; i++) {
        if (i == ref) continue;
        distancias[total] = CalcularDistancia(notas, ref, i);
        indices[total] = i;
        total++;
    }

    for (int i = 0; i < total - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < total; j++) {
            if (distancias[j] < distancias[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            float distanciaTemp = distancias[i];
            distancias[i] = distancias[menor];
            distancias[menor] = distanciaTemp;

            int indiceTemp = indices[i];
            indices[i] = indices[menor];
            indices[menor] = indiceTemp;
        }
    }

    formt(1);
    moldura();
    printf("Perfis mais proximos de %s\n", nomes[ref]);
    moldura();
    formt(1);

    for (int i = 0; i < total; i++) {
        printf("%d - %-20s ............... %.2f\n", i + 1, nomes[indices[i]], distancias[i]);
    }

    free(distancias);
    free(indices);
    formt(10);
}

void AnalisarPreferencias(char (*nomes)[TAM_NOME], float *notas, int quant) {
    if (quant < 2) {
        printf("E necessario ter pelo menos 2 pessoas cadastradas para essa analise.\n");
        formt(10);
        return;
    }

    static const char *nomesPref[QTD_PREF] = {
        "Musica", "Cinema", "Jogos", "Esportes", "Leitura", "Programacao"
    };

    printf("Primeira pessoa\n");
    int pos1 = BuscaPessoa(nomes, quant);

    printf("Segunda pessoa\n");
    int pos2 = BuscaPessoa(nomes, quant);

    if (pos1 == -1 || pos2 == -1) {
        printf("Nao foi possivel analisar: uma ou ambas as pessoas nao foram encontradas.\n");
        formt(10);
        return;
    }

    float diferencas[QTD_PREF];
    float menorDiferenca = -1.0f;

    formt(1);
    moldura();
    printf("ANALISE DE PERFIS\n");
    moldura();
    formt(1);
    printf("%s X %s\n", nomes[pos1], nomes[pos2]);
    formt(1);

    printf("%-12s %10s %10s %10s\n", "Preferencia", nomes[pos1], nomes[pos2], "Diferenca");
    printf("-----------------------------------------------\n");

    for (int j = 0; j < QTD_PREF; j++) {
        float n1 = notas[pos1 * QTD_PREF + j];
        float n2 = notas[pos2 * QTD_PREF + j];
        float diff = fabs(n1 - n2);
        diferencas[j] = diff;

        printf("%-12s %10.1f %10.1f %10.1f\n", nomesPref[j], n1, n2, diff);

        if (menorDiferenca < 0 || diff < menorDiferenca) {
            menorDiferenca = diff;
        }
    }

    printf("-----------------------------------------------\n");
    printf("Distancia euclidiana: %.2f\n", CalcularDistancia(notas, pos1, pos2));

    formt(1);
    printf("Preferencias mais semelhantes:\n");

    for (int j = 0; j < QTD_PREF; j++) {
        if (fabs(diferencas[j] - menorDiferenca) < 0.0001f) {
            printf("%s\n", nomesPref[j]);
        }
    }

    formt(10);
}