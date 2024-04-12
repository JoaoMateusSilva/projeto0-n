#define TOTAL 100 //define o TOTAL com o valor de 100.
#define CATEGORIA 100 //define o máximo de caractéres da CATEGORIA como 100.
#define DESCRICAO 300 //define o máximo de caractéres da DESCRIÇÃO como 300.
//tudo isso para que ao criar uma tarefas você tenha certa limitações para manter o programa organizado e padronizado.

typedef struct { //struct usado na hora de criar tarefas utilizados para definir a prioridade como um número inteiro e a descrição e a categoria como arrays de 300 e 100 de espaços respectivamente.
    int prioridade;
    char descricao[DESCRICAO];
    char categoria[CATEGORIA];
} Tarefa;

typedef enum {OK, MAX_TAREFA, SEM_TAREFAS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, NUMERO_INVALIDO} ERROS; //aqui define os erros possíveis na hora da execução das tarefas.

typedef ERROS (*funcao)(Tarefa[], int*);//define se há algum tipo de erro nas funções.

ERROS criar(Tarefa tarefas[], int *pos);
ERROS deletar(Tarefa tarefas[], int *pos);
ERROS listar(Tarefa tarefas[], int *pos);
ERROS salvar(Tarefa tarefas[], int *pos);
ERROS carregar(Tarefa tarefas[], int *pos);
ERROS exportar(Tarefa tarefas[], int *pos);

void clearBuffer();