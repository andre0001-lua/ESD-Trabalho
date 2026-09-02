Pendente para a finalização da V1

1 - Definição da Matriz de Notas na main: Trocar a matriz estática bidimensional float notas[MAX_PESSOAS][QTD_PREF] por um ponteiro simples float *notas = NULL; alocado via malloc

2 - Alocação Dinâmica com Bloco Único: Ao cadastrar ou definir a quantidade de pessoas em tempo de execução, alocar espaço com malloc(quantidade * QTD_PREF * sizeof(float)).

3 - Verificação de Ponteiro: Validar se o ponteiro retornado pelo malloc não é NULL antes de usá-lo.

4 - Fórmula de Acesso Linear: Ajustar todas as funções que leem ou gravam notas para substituir o acesso notas[i][j] pelo cálculo linear notas[i * QTD_PREF + j].

5 - Atualização dos Cabeçalhos (func.h e func.c): Mudar os parâmetros de matriz float notas[][QTD_PREF] para float *notas em todas as funções (CadastrarPessoas, CalcularDistancia, ExibirPessoas, CompararDuasPessoas, EncontrarMaisSemelhante, ExibirRankingAfinidade e AnalisarPreferencias).

6 - Liberação de Memória: Incluir a chamada obrigatória de free(notas) na opção 0 (Encerrar) ou no término da main antes do return 0.

Testes Gerais - X

favor avisar no grupo wpp para que n haja repetições de tarefas

data de entrega 4 de setembro
