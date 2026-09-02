#define MAX_PESSOAS 30
#define QTD_PREF 6
#define TAM_NOME 50
void moldura();
void opcoes();
void formt(int q);
float LerNotaValida(void);
int BuscaPessoa(char nomes[][TAM_NOME], int quant);
float CalcularDistancia(float notas[][QTD_PREF], int pont1, int pont2);
void CadastrarPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int *quant);
void EncontrarMaisSemelhante(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
void menu(char nomes[][TAM_NOME], float notas[][QTD_PREF], int *quant);
void CompararDuasPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
void ExibirPessoas(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
void ExibirRankingAfinidade(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);
void AnalisarPreferencias(char nomes[][TAM_NOME], float notas[][QTD_PREF], int quant);