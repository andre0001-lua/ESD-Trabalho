//v1
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#define MAX_PESSOAS 30
#define QTD_PREF 6
#define TAM_NOME 50

// Imprime a linha divisória padronizada do sistema no console.
void moldura();
// Exibe a lista com as opções disponíveis no menu principal.
void opcoes();
// Pula uma quantidade 'q' de linhas para espaçamento visual na tela.
void formt(int q);
// Lê e valida uma nota digitada, garantindo que o valor esteja no intervalo de 0.0 a 10.0.
float LerNotaValida(void);
// Solicita um nome via teclado e busca sua ocorrência no vetor, retornando o índice ou -1 se não encontrar.
int BuscaPessoa(char nomes[][TAM_NOME], int quant);
// Calcula a distância euclidiana entre os perfis de duas pessoas (pont1 e pont2) com base em suas notas.
float CalcularDistancia(float notas[][QTD_PREF], int pont1, int pont2);
// Cadastra novos usuários e suas respectivas notas para as preferências, atualizando o total cadastrado (*quant).
void CadastrarPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int *quant);
// Identifica e exibe a pessoa cadastrada mais próxima de uma pessoa de referência escolhida.
void EncontrarMaisSemelhante(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
// Busca dois perfis informados pelo usuário e exibe a distância euclidiana entre eles.
void CompararDuasPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
// Exibe todos os nomes e suas notas em formato tabular com cabeçalho alinhado.
void ExibirPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);

void ExibirRankingAfinidade(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);

void AnalisarPreferencias(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
// Gera e exibe uma lista ordenada dos perfis mais próximos a uma pessoa de referência (menor para maior distância).
void ExibirRankingAfinidade(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
