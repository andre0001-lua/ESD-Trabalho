//v4
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#ifndef V4_ANDRELUIS_ERIKSOARES_RAFAELCOSTA_ROBERTOALVES_H
#define V4_ANDRELUIS_ERIKSOARES_RAFAELCOSTA_ROBERTOALVES_H

#define MAX_PESSOAS 30
#define QTD_PREF 6
#define TAM_NOME 50

typedef struct{
    char nome[TAM_NOME];
    float notas[QTD_PREF];
} Pessoa;

// Imprime a linha divisória padronizada do sistema no console.
void moldura();
// Exibe a lista com as opções disponíveis no menu principal.
void opcoes();
// Pula uma quantidade 'q' de linhas para espaçamento visual na tela.
void formt(int q);
// Lê e valida uma nota digitada, garantindo que o valor esteja no intervalo de 0.0 a 10.0.
float LerNotaValida(void);
// Solicita um nome via teclado e busca sua ocorrência no vetor, retornando o índice ou -1 se não encontrar.
int BuscaPessoa(Pessoa pessoas[], int quant);
// Calcula a distância euclidiana entre os perfis de duas pessoas (pont1 e pont2) com base em suas notas.
float CalcularDistancia(Pessoa pessoas[], int pont1, int pont2);
// Cadastra novos usuários e suas respectivas notas para as preferências, atualizando o total cadastrado (*quant).
void CadastrarPessoas(Pessoa pessoas[], int *quant, int capacidade);
// Identifica e exibe a pessoa cadastrada mais próxima de uma pessoa de referência escolhida.
void EncontrarMaisSemelhante(Pessoa pessoas[], int quant);
// Busca dois perfis informados pelo usuário e exibe a distância euclidiana entre eles.
void CompararDuasPessoas(Pessoa pessoas[], int quant);
// Exibe todos os nomes e suas notas em formato tabular com cabeçalho alinhado.
void ExibirPessoas(Pessoa pessoas[], int quant);

void ExibirRankingAfinidade(Pessoa pessoas[], int quant);

void AnalisarPreferencias(Pessoa pessoas[], int quant);

#endif