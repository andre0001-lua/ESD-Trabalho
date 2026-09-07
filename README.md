Pendente para a finalização da V1

1 - Definição da Matriz de Notas na main: Trocar a matriz estática bidimensional float notas[MAX_PESSOAS][QTD_PREF] por um ponteiro simples float *notas = NULL; alocado via malloc |OK|

2 - Alocação Dinâmica com Bloco Único: Ao cadastrar ou definir a quantidade de pessoas em tempo de execução, alocar espaço com malloc(quantidade * QTD_PREF * sizeof(float)). |OK|

3 - Verificação de Ponteiro: Validar se o ponteiro retornado pelo malloc não é NULL antes de usá-lo. |OK|

4 - Fórmula de Acesso Linear: Ajustar todas as funções que leem ou gravam notas para substituir o acesso notas[i][j] pelo cálculo linear notas[i * QTD_PREF + j]. |OK|

5 - Atualização dos Cabeçalhos (func.h e func.c): Mudar os parâmetros de matriz float notas[][QTD_PREF] para float *notas em todas as funções (CadastrarPessoas, CalcularDistancia, ExibirPessoas, CompararDuasPessoas, EncontrarMaisSemelhante, ExibirRankingAfinidade e AnalisarPreferencias). |OK|

6 - Liberação de Memória: Incluir a chamada obrigatória de free(notas) na opção 0 (Encerrar) ou no término da main antes do return 0. 

Testes Gerais - |OK|

favor avisar no grupo wpp para que n haja repetições de tarefas

data de entrega 11 de setembro


||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
Para o relatório
se alguém quiser terminar isso aq

a) Por que uma matriz é adequada para armazenar as notas na primeira versão?
    R-Porque organiza os dados de forma bidimensional (como uma planilha ou tabela), permitindo correlacionar diretamente um conjunto fixo de características (preferências) a cada elemento cadastrado (pessoas) por meio de índices.
b) O que representa uma linha da matriz?
    R-Representa uma pessoa cadastrada (o índice da linha corresponde ao índice da pessoa no vetor de nomes).
c) O que representa uma coluna?
    R-Representa uma categoria de preferência específica com suas respectivas notas(Música, Cinema, Jogos, etc.).
d) Por que uma distância euclidiana menor indica maior semelhança?
    R-Porque cada vetor de notas funciona como as coordenadas de um ponto em um espaço geométrico. Quanto menores forem as diferenças entre as notas de duas pessoas, mais próximos esses pontos estarão no espaço, resultando em uma distância menor e, portanto, em maior afinidade de perfis.
e) Qual é a principal dificuldade de manter nomes e notas em estruturas paralelas?
    R-A falta de um ponto de referência 100% entre os dados. Como a relação depende principalmente do índice (nomes[i] e notas[i]), qualquer ordenação ou manipulação que altere a posição de um vetor sem atualizar o outro faz o sistema associar as notas de uma pessoa ao nome de outra.
f) Que problema a `struct Pessoa` resolve?
    R-
g) Qual é a diferença entre:

    Pessoa pessoas[30];

    e um vetor de pessoas criado com `malloc`?
    
    R-

h) Qual é a diferença conceitual entre:

    Pessoa *p;
    e:
    Pessoa p;

    R-

i) Por que um vetor de ponteiros pode ser útil para gerar o ranking sem modificar a ordem do cadastro?
    R-

j) Em quais momentos do programa a memória dinâmica precisa ser liberada?
    R- No encerramento do programa: Os dados principais (nomes e notas) devem ser liberados no final da main (ou na opção 0 de saída).

