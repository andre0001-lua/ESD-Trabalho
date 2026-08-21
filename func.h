#define MAX_PESSOAS 30
#define QTD_PREF 6
#define TAM_NOME 50
void moldura();
void opcoes();
void formt(int q);
float LerNotaValida(void);
int buscaPessoa(char nomes[][TAM_NOME], int quant, const char *nomeProcurado);
float CalcularDistancia(float notas[][QUANT_ESC], int pont1, int pont2);
void CadastrarPessoas(char nomes[][TAM_NOME], float notas[][QUANT_ESC], int *quant);
