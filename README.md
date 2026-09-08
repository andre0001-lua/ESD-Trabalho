Pendente para a finalização da V4
(ainda não iniciada)

1 - Vetor dinâmico de struct Pessoa: Trocar Pessoa pessoas[MAX_PESSOAS] por Pessoa *pessoas alocado via malloc(quantidade * sizeof(Pessoa)).

2 - Verificação de Ponteiro: Validar se o malloc não retornou NULL.

3 - Atualização dos Cabeçalhos: Ajustar as assinaturas de função conforme necessário para receber o ponteiro dinâmico.

4 - Liberação de Memória: Incluir free(pessoas) no encerramento do programa.

5 - Preservação das funcionalidades da V1/V3.

Testes Gerais -

favor avisar no grupo wpp para que n haja repetições de tarefas

data de entrega [quinta-feira]

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

Pendente para a finalização da V5
(ainda não iniciada)

1 - Vetor de ponteiros para struct: Criar Pessoa *ranking[MAX_PESSOAS] (ou dinâmico) armazenando endereços das pessoas cadastradas.

2 - Construção do ranking sem cópia: Preencher o vetor de ponteiros ordenado por afinidade, sem duplicar os dados nem alterar a ordem original do cadastro.

3 - Uso correto de -> : Acessar os campos da struct através dos ponteiros usando o operador seta.

4 - Liberação de Memória: Confirmar que só o vetor de pessoas original (não o de ponteiros) precisa de free.

5 - Preservação das funcionalidades da V1/V3/V4.

Testes Gerais -

favor avisar no grupo wpp para que n haja repetições de tarefas

data de entrega [quinta-feira]

||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

Pendente no relatório

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
