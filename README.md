Pendente para a finalização da V5
(ainda não iniciada)

1 - Criação do Vetor de Ponteiros no Ranking (ExibirRankingAfinidade)
    .
        Declarar ou alocar um vetor onde cada elemento é um endereço: Pessoa *ranking[quant - 1]; ou Pessoa **ranking = malloc((quant - 1) * sizeof(Pessoa *)); *(Caso o vetor de ponteiros ranking e o vetor auxiliar de distâncias sejam alocados via malloc, garantir a liberação de ambos com free() antes de sair da função ExibirRankingAfinidade.)*

    .
        Apontar cada posição do ranking diretamente para o registro original da pessoa candidata: ranking[total] = &pessoas[i];.  

2 - Construção do ranking sem cópia: Preencher o vetor de ponteiros ordenado por afinidade, sem duplicar os dados nem alterar a ordem original do cadastro.

3 - Uso correto de -> : Acessar os campos da struct através dos ponteiros usando o operador seta.

4 - Liberação de Memória: Confirmar que só o vetor de pessoas original (não o de ponteiros) precisa de free.

5 - Ordenação por Troca de Endereços (Sem Troca de Structs Inteiras):
    .
    Na ordenação do ranking (por seleção ou bolha), manter o vetor de distâncias sincronizado trocando apenas os ponteiros de endereço:
        Pessoa *tempPessoa = ranking[i];
        ranking[i] = ranking[menor];
        ranking[menor] = tempPessoa;
    .
    O cadastro original pessoas[] deve permanecer 100% intacto em sua ordem de cadastro (requisito obrigatório da Seção 16).

6 - Preservação das funcionalidades da V1/V3/V4.

Testes Gerais -

favor avisar no grupo wpp para que n haja repetições de tarefas

data de entrega [quinta-feira]

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
