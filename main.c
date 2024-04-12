#include <stdio.h>
#include <string.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, salvar, carregar, exportar};

    Tarefa tarefas[TOTAL];
    
    int pos;
    
    ERROS erro = fs[4](tarefas, &pos);
    if(erro != OK){
        if(erro == ABRIR){
            printf("erro ao abrir o arquivo\n");
            pos = 0;
        } 
        else if(erro == FECHAR){
            printf("erro ao fechar o arquivo\n");
            pos = 0;
        }
        else if(erro == LER){
            printf("erro ao ler no arquivo\n");
            pos = 0;
        }
    }

    int opcao;
    
    do {
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("4 - Exportar tarefas\n");
        printf("0 - Sair\n");
        printf("Entre com uma opcao: ");
        
        int i = scanf("%d", &opcao);

        printf("Opcao escolhida: %d\n", opcao);
        
        opcao--;
        if(opcao > 4)
            printf("Opcao invalida\n");
        if(opcao < 0)
            printf("Opcao invalida\n");
        else if(opcao == 1) {
            ERROS errocriar = fs[0](tarefas, &pos);
            if(errocriar == MAX_TAREFA)
                printf("maximo de tarefas alcancadas\n");
        } else if (opcao == 2) {
            ERROS errodeletar = fs[1](tarefas, &pos);
            if(errodeletar == SEM_TAREFAS)
                printf("sem tarefas para deletar\n");
            else if(errodeletar == NAO_ENCONTRADO)
                printf("tarefa nao existe\n");          
        } else if (opcao == 3) {
            ERROS errolistar = fs[2](tarefas, &pos);
            if(errolistar == SEM_TAREFAS)
                printf("sem tarefas para listar\n");
        } else if (opcao == 3) {
            ERROS erroexportar = fs[4](tarefas, &pos);
            if(erroexportar == SEM_TAREFAS)
                printf("sem tarefas para exportar\n");
        } else {
            printf("Sair...\n");
        }
            
    } while(opcao >= 0);

    ERROS errosalvar = fs[3](tarefas, &pos);
    if(erro == ABRIR)
        printf("erro ao abrir o arquivo\n");
    else if(erro == FECHAR)
        printf("erro ao fechar o arquivo\n");
    else if(erro == ESCREVER)
        printf("erro ao escrever no arquivo\n");
}
