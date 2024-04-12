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
    
   do{
        printf("\nMenu principal\n"); 
        printf("1 - Criar tarefa\n"); 
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: "); 

        scanf("%d", &opcao); 
        opcao--;
        if(opcao > 3)
            printf("Opcao invalida\n"); 
        else if(opcao >= 0)
            fs[opcao](tarefas, &pos);
        else
            printf("Sair...\n");
        
        switch (erro) {
        case OK:
            break;
        case MAX_TAREFA:
            printf("Erro: Não é possível criar mais tarefas.\n");
            break;
        case SEM_TAREFAS:
            printf("Erro: Não existem tarefas para deletar ou listar.\n");
            break;
        case NAO_ENCONTRADO:
            printf("Erro: Tarefa não encontrada.\n");
            break;
        case NUMERO_INVALIDO:
            printf("Erro: Prioridade inválida.\n");
            break;
        case ABRIR:
            printf("Erro: Não foi possível abrir o arquivo.\n");
            break;
        case LER:
            printf("Erro: Não foi possível ler o arquivo.\n");
            break;
        case ESCREVER:
            printf("Erro: Não foi possível escrever no arquivo.\n");
            break;
        case FECHAR:
            printf("Erro: Não foi possível fechar o arquivo.\n");
            break;
        default:
            printf("Erro desconhecido.\n");
            break;
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
