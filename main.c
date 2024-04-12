#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, salvar, carregar}; //aqui é criado um array com as funções disponiveis para facilitar a chamada das mesmas.

    Tarefa tarefas[TOTAL]; //nesse array é definido como tamanho (TOTAL=100) de tarefas possíveis para criar.
    
    int pos;
    
    ERROS erro = fs[4](tarefas, &pos); //aqui é chamada a função carregar através do array criado anteriormente.
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

    int opcao; // as opções são escolhidas através de um numero inteiro que o úsuario digitar.
    
    do {
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("0 - Sair\n");
        printf("Entre com uma opcao: ");
        
        int i = scanf("%d", &opcao);

        printf("Opcao escolhida: %d\n", opcao);
        
        opcao--;
        if(opcao > 3)
            printf("Opcao invalida\n"); //caso o úsuario digite um número acima de 3 o retorno é dado como inválido.
        if(opcao < 0)
            printf("Opcao invalida\n"); //caso o úsuario digite um número menor que 0 o retorno é dado como inválido.
        else if(opcao == 1) {
            ERROS erro = fs[0](tarefas, &pos);
            if(erro == MAX_TAREFA)
                printf("maximo de tarefas alcancadas\n");
        } else if (opcao == 2) {
            ERROS erro = fs[1](tarefas, &pos);
            if(erro == SEM_TAREFAS)
                printf("sem tarefas para deletar\n");
            else if(erro == NAO_ENCONTRADO)
                printf("tarefa nao existe\n");          
        } else if (opcao == 3) {
            ERROS erro = fs[2](tarefas, &pos);
            if(erro == SEM_TAREFAS)
                printf("sem tarefas para listar\n");
        } else {
            printf("Sair...\n");
        }
            
    } while(opcao >= 0); //enquanto a opção for diferente de zero o programa irá repetir as etapas anteriores.

    ERROS erro = fs[3](tarefas, &pos); //se a opção escolhida for a 0 o programa chamará função 3(salvar) e encerrará o programa.
    if(erro == ABRIR)
        printf("erro ao abrir o arquivo\n");
    else if(erro == FECHAR)
        printf("erro ao fechar o arquivo\n");
    else if(erro == ESCREVER)
        printf("erro ao escrever no arquivo\n");
}
