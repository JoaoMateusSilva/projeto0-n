#include <stdio.h>
#include "tarefas.h"

#define CATEGORIA_SIZE 100
#define DESCRICAO_SIZE 300

int main() {
    funcao fs[] = {criar, deletar, listar, salvar, carregar};

    Tarefa tarefas[TOTAL];
    int pos;
    ERROS erro = fs[4](tarefas, &pos);
    if (erro != OK)
        pos = 0;

    int opcao;
    char categoria[CATEGORIA_SIZE];
    char nomeArquivo[100];

    do {
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("4 - Exportar tarefas\n");
        printf("5 - Carregar tarefas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        clearBuffer();

        switch (opcao) {
            case 1:
                fs[0](tarefas, &pos);
                break;
            case 2:
                fs[1](tarefas, &pos);
                break;
            case 3:
                printf("Entre com a categoria: ");
                fgets(categoria, CATEGORIA_SIZE, stdin);
                fs[2](tarefas, pos, categoria);
                break;
            case 4:
                printf("Entrar com o nome do arquivo que esta exportanto:  ");
                fgets(nomeArquivo, 100, stdin);
                fs[3](tarefas, pos, nomeArquivo);
                break;
            case 5:
                printf("Entrar com o arquivo de load: ");
                fgets(nomeArquivo, 100, stdin);
                fs[4](tarefas, &pos, nomeArquivo);
                break;
            case 0:
                printf("Sair...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    fs[3](tarefas, pos);
}
