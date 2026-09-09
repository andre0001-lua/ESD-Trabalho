//v2
//André Luís Paiva
//Erik Soares Mendonça
//Roberto Alves Antunes
//Rafael Costa Oliveira

#define QTD_PREF 6
#define TAM_NOME 50

#define QTD_PREF 6
#define TAM_NOME 50

// Imprime a linha divisória padronizada do sistema no console.
void moldura(void);

// Exibe a lista com as opções disponíveis no menu principal.
void opcoes(void);

// Pula uma quantidade 'q' de linhas para espaçamento visual na tela.
void formt(int q);

// Lê e valida uma nota digitada, garantindo que o valor esteja no intervalo de 0.0 a 10.0.
float LerNotaValida(void);

// Solicita um nome via teclado e busca sua ocorrência, retornando o índice ou -1.
int BuscaPessoa(char (*nomes)[TAM_NOME], int quant);

// Calcula a distância euclidiana linear entre os perfis de duas pessoas (pont1 e pont2).
float CalcularDistancia(float *notas, int pont1, int pont2);

// Cadastra novos usuários validando contra a capacidade dinâmica total alocada.
void CadastrarPessoas(char (*nomes)[TAM_NOME], float *notas, int *quant, int capacidade);

// Identifica e exibe a pessoa cadastrada mais próxima de uma pessoa de referência escolhida.
void EncontrarMaisSemelhante(char (*nomes)[TAM_NOME], float *notas, int quant);

// Busca dois perfis informados pelo usuário e exibe a distância euclidiana entre eles.
void CompararDuasPessoas(char (*nomes)[TAM_NOME], float *notas, int quant);

// Exibe todos os nomes e suas notas em formato tabular.
void ExibirPessoas(char (*nomes)[TAM_NOME], float *notas, int quant);

// Gera e exibe o ranking ordenado de afinidade em relação a uma pessoa de referência.
void ExibirRankingAfinidade(char (*nomes)[TAM_NOME], float *notas, int quant);

// Realiza a análise comparativa preferência por preferência entre duas pessoas.
void AnalisarPreferencias(char (*nomes)[TAM_NOME], float *notas, int quant);