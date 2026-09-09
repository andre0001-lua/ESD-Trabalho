//v5
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#include "V5_AndreLuis_ErikSoares_RafaelCosta_RobertoAlves.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void moldura() {
	printf("========================================\n");
}
void opcoes() {
	printf("1 - Cadastrar Pessoas\n");
	printf("2 - Exibir pessoas e preferências\n");
	printf("3 - Buscar pessoa pelo nome\n");
	printf("4 - Comparar duas pessoas\n");
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

float LerNotaValida() {
	float nota;
	while(1){
		if (scanf("%f", &nota) == 1 && nota >= 0.0f && nota <= 10.0f) {
			return nota;
		}
		printf("Nota invalida! Digite um valor entre 0 e 10: ");
		while(getchar() != '\n');
	}
}

void CadastrarPessoas(Pessoa pessoas[], int *quant, int capacidade) {
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
        scanf("%49[^\n]", pessoas[j].nome);
        while (getchar() != '\n');

        for (int k = 0; k < QTD_PREF; k++) {
            printf("Digite a nota para a preferencia %d: ", k + 1);
            pessoas[j].notas[k] = LerNotaValida();
        }
        while (getchar() != '\n');
    }

    *quant += novos;
    formt(10);
}

void ExibirPessoas(Pessoa pessoas[], int quant)
{
	if (quant == 0)
	{
		printf("Nenhuma pessoa cadastrada ainda.\n");
		formt(10);
		return;
	}

	int maiorNome = 4;

	for (int i = 0; i < quant; i++)
	{
		int tam = strlen(pessoas[i].nome);
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
		printf("%-*s", maiorNome, pessoas[i].nome);
		for (int j = 0; j < QTD_PREF; j++)
		{
			printf(" %6.1f", pessoas[i].notas[j]);
		}
		printf("\n");
	}

	moldura();
	formt(10);

}

int BuscaPessoa(Pessoa pessoas[], int quant){
	if (quant == 0) {
		return -1;
	}

	char nomeBuscando[TAM_NOME];
	printf("Digite o nome que deseja buscar: ");
	scanf("%49[^\n]", nomeBuscando);
	while (getchar() != '\n');

	for (int i=0; i<quant; i++){
		if (strcmp(pessoas[i].nome, nomeBuscando) == 0){
			return i;
		}
	}
	return -1;
}

float CalcularDistancia(Pessoa pessoas[], int pos1, int pos2){
	float soma = 0;
	for(int j=0; j<QTD_PREF;j++){
		float diff = pessoas[pos1].notas[j] - pessoas[pos2].notas[j];
		soma = soma + (diff*diff);
	}
	return sqrt(soma);
}

void CompararDuasPessoas(Pessoa pessoas[], int quant) {
	if (quant < 2) {
		printf("É necessário ter pelo menos 2 pessoas cadastradas para essa comparação.\n");
		formt(10);
		return;
	}

	float dist;

	printf("Primeira pessoa\n");
	int pos1 = BuscaPessoa(pessoas, quant);

	printf("Segunda pessoa\n");
	int pos2 = BuscaPessoa(pessoas, quant);

	if (pos1 == -1 || pos2 == -1) {
		printf("Não foi possível comparar: uma ou ambas as pessoas não foram encontradas.\n");
		formt(10);
		return;
	}

	dist = CalcularDistancia(pessoas, pos1, pos2);

	moldura();
	printf("COMPARAÇÃO DE PERFIS\n");
	moldura();
	formt(1);
	printf("%s X %s\n", pessoas[pos1].nome, pessoas[pos2].nome);
	printf("Distância: %.2f\n", dist);
	formt(10);
}

void EncontrarMaisSemelhante(Pessoa pessoas[], int quant)
{
	if (quant < 2)
	{
		printf ("É necessário ter pelo menos 2 pessoas cadastradas para essa busca.\n");
		formt(10);
		return;
	}

	printf ("Pessoa de referência\n");
	int ref = BuscaPessoa(pessoas, quant);

	if (ref == -1)
	{
		printf ("Pessoa não encontrada.\n");
		formt(10);
		return;
	}

	float *distancias = (float *) malloc(quant * sizeof(float));
	if (distancias == NULL) {
		printf("Erro de alocação temporária.\n");
		return;
	}

	float menorDistancia = -1;

	moldura ();
	printf ("BUSCA DE PERFIS SEMELHANTES\n");
	moldura();
	formt(1);
	printf ("Pessoa de referencia: %s\n", pessoas[ref].nome);
	formt(1);

	for (int i = 0; i < quant; i++)
	{
		if (i == ref)
		{
			continue;
		}

		float dist = CalcularDistancia(pessoas, ref, i);
		distancias[i] = dist;
		printf ("Distância para %s: %.2f\n", pessoas[i].nome, dist);

		if (menorDistancia == -1 || dist < menorDistancia)
		{
			menorDistancia = dist;
		}
	}

	formt(1);
	printf ("----------------------------------\n");
	printf ("PERFIL MAIS SEMELHANTE\n");
	printf ("----------------------------------\n");

	for (int i = 0; i < quant; i++)
	{
		if (i == ref)
		{
			continue;
		}

		if (fabs(distancias[i] - menorDistancia) < 0.0001f)
		{
			printf ("%s\n", pessoas[i].nome);
		}
	}

	printf ("Distância: %.2f\n", menorDistancia);
	free(distancias);
	formt(10);

}

void ExibirRankingAfinidade(Pessoa pessoas[], int quant) {
	if (quant < 2) {
		printf("É necessário ter pelo menos 2 pessoas cadastradas para essa busca.\n");
		formt(10);
		return;
	}

	printf("Pessoa de referência\n");
	int ref = BuscaPessoa(pessoas, quant);

	if (ref == -1) {
		printf ("Pessoa não encontrada.\n");
		formt(10);
		return;
	}

	float *distancias = (float *) malloc((quant - 1) * sizeof(float));
	// vetor de ponteiros: cada posição vai guardar o ENDEREÇO de uma Pessoa já existente
	// em "pessoas", em vez de copiar a struct inteira ou guardar só o índice dela
	Pessoa **ranking = (Pessoa **) malloc((quant - 1) * sizeof(Pessoa *));

	if (distancias == NULL || ranking == NULL) {
		printf("Erro de alocação temporária.\n");
		if (distancias != NULL) free(distancias);
		if (ranking != NULL) free(ranking);
		return;
	}

	int total = 0;

	for (int i = 0; i < quant; i++) {
		if (i == ref) continue;

		distancias[total] = CalcularDistancia(pessoas, ref, i);
		ranking[total] = &pessoas[i]; // aponta pro registro original, não copia nada
		total++;
	}

	for (int i = 0; i < total - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < total; j++) {
			if (distancias[j] < distancias[menor]) menor = j;
		}

		if (menor != i) {
			float distanciaTemp = distancias[i];
			distancias[i] = distancias[menor];
			distancias[menor] = distanciaTemp;

			// troca só os ENDEREÇOS guardados no ranking, nunca as structs Pessoa em si
			// (isso é o que garante que o cadastro original em "pessoas" nunca muda de ordem)
			Pessoa *tempPessoa = ranking[i];
			ranking[i] = ranking[menor];
			ranking[menor] = tempPessoa;
		}
	}

	formt(1);
	moldura();
	printf("Perfis mais proximos de %s\n", pessoas[ref].nome);
	moldura();
	formt(1);

	for (int i = 0; i < total; i++) {
		// -> porque ranking[i] é um ponteiro (Pessoa *), não uma Pessoa direto
		printf("%d - %-20s ............... %.2f\n", i + 1, ranking[i]->nome, distancias[i]);
	}

	// libera só o vetor de ponteiros (o "índice" do ranking) e o vetor de distâncias;
	// os dados de cada pessoa continuam vivos dentro de "pessoas", que é liberado no main()
	free(distancias);
	free(ranking);
	formt(10);
}

void AnalisarPreferencias(Pessoa pessoas[], int quant) {
	if (quant < 2) {
		printf("É necessário ter pelo menos 2 pessoas cadastradas para essa análise.\n");
		formt(10);
		return;
	}

	static const char *nomesPref[QTD_PREF] = {
		"Musica", "Cinema", "Jogos", "Esportes", "Leitura", "Programacao"
	};

	printf ("Primeira pessoa\n");
	int pos1 = BuscaPessoa(pessoas, quant);

	printf ("Segunda pessoa\n");
	int pos2 = BuscaPessoa(pessoas, quant);

	if (pos1 == -1 || pos2 == -1) {
		printf ("Não foi possível analisar: uma ou ambas as pessoas não foram encontradas.\n");
		return;
	}

	float diferencas[QTD_PREF];
	float menorDiferenca = -1;

	formt(1);
	moldura();
	printf ("ANALISE DE PERFIS\n");
	moldura();
	formt(1);
	printf ("%s X %s\n", pessoas[pos1].nome, pessoas[pos2].nome);
	formt(1);

	printf("%-12s %10s %10s %10s\n", "Preferencia", pessoas[pos1].nome, pessoas[pos2].nome, "Diferenca");
	printf ("-----------------------------------------------\n");

	for (int j = 0; j < QTD_PREF; j++) {
		float diff = fabs(pessoas[pos1].notas[j] - pessoas[pos2].notas[j]);
		diferencas[j] = diff;

		printf("%-12s %10.1f %10.1f %10.1f\n", nomesPref[j], pessoas[pos1].notas[j], pessoas[pos2].notas[j], diff);
		if (menorDiferenca == -1 || diff < menorDiferenca) {
			menorDiferenca = diff;
		}
	}

	printf ("-----------------------------------------------\n");
	printf("Distância euclidiana: %.2f\n", CalcularDistancia(pessoas, pos1, pos2));

	formt(1);
	printf ("Preferencias mais semelhantes:\n");

	for (int j = 0; j < QTD_PREF; j++) {
		if (fabs(diferencas[j] - menorDiferenca) < 0.0001f) {
			printf ("%s\n", nomesPref[j]);
		}
	}

	formt(10);
}