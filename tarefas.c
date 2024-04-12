#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos){
    if(*pos >= TOTAL)
        return MAX_TAREFA;

    printf("Entre com a prioridade: ");
    scanf("%d", &tarefas[*pos].prioridade);

    if(tarefas[*pos].prioridade < 1 || tarefas[*pos].prioridade > 10) 
        return NUMERO_INVALIDO;
    
    clearBuffer();
    
    printf("Entre com a categoria: ");
    fgets(tarefas[*pos].categoria, CATEGORIA, stdin);
    tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0';

    printf("Entre com a descricao: ");
    fgets(tarefas[*pos].descricao, DESCRICAO, stdin);
    tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao, "\n")] = '\0';

    *pos = *pos + 1;
    return OK;
}

ERROS deletar(Tarefa tarefas[], int *pos){
    if(*pos == 0)
        return SEM_TAREFAS; 
    
    int pos_deletar; 
    
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar); 
    
    pos_deletar--;
    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos){
    if(*pos == 0)
        return SEM_TAREFAS;

    char categoria[CATEGORIA];
    printf("Entre com a categoria (deixe em branco para listar todas): ");
    fgets(categoria, CATEGORIA, stdin);
    categoria[strcspn(categoria, "\n")] = '\0';

    int encontrados = 0;
    for(int i=0; i<*pos; i++){
        if(strcmp(categoria, "") == 0 || strcmp(tarefas[i].categoria, categoria) == 0) {
            printf("Pos: %d\t", i+1);
            printf("Prioridade: %d\t", tarefas[i].prioridade);
            printf("Categoria: %s\t", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            encontrados++;
        }
    }

    if(encontrados == 0)
        printf("Nenhuma tarefa encontrada para a categoria %s\n", categoria);

    return OK;
}

}

ERROS salvar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "wb");
    if(f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS exportar(Tarefa tarefas[], int *pos){
    if(*pos == 0)
        return SEM_TAREFAS;

    char categoria[CATEGORIA];
    printf("Entre com a categoria (deixe em branco para exportar todas): ");
    fgets(categoria, CATEGORIA, stdin);
    categoria[strcspn(categoria, "\n")] = '\0';

    char nome_arquivo[100];
    printf("Entre com o nome do arquivo para exportar: ");
    fgets(nome_arquivo, 100, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    FILE *f = fopen(nome_arquivo, "w");
    if(f == NULL)
        return ABRIR;

    int encontrados = 0;
    for(int i=0; i<*pos; i++){
        if(strcmp(categoria, "") == 0 || strcmp(tarefas[i].categoria, categoria) == 0) {
            fprintf(f, "Pos: %d\t", i+1);
            fprintf(f, "Prioridade: %d\t", tarefas[i].prioridade);
            fprintf(f, "Categoria: %s\t", tarefas[i].categoria);
            fprintf(f, "Descricao: %s\n", tarefas[i].descricao);
            encontrados++;
        }
    }

    if(encontrados == 0)
        printf("Nenhuma tarefa encontrada para a categoria %s\n", categoria);

    if(fclose(f))
        return FECHAR;

    return OK;
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
