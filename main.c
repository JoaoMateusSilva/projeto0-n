#include <stdio.h>

int main(){
    int pos = 0;
    Tarefa tarefas[TOTAL];
    
    int opcao;
    do {
        printf("\n Menu principal\n");
        printf("1 - Criar Tarefa\n");
        printf("2 - deletar tarefa\n");
        printf("3 - listar tarefas\n");
        printf("0 - Sair \n");
        printf("Entre com uma opcao: ");
        
        int i = scanf("%d", &opcao);
        
        printf("Opcao escolhida: %d\n", opcao);
        if (opcao == 1) {
            int erro = criar(tarefas, &pos);
        }else if (opcao == 2) {
            int erro = deletar(tarefas, &pos);
        }else if (opcao == 3) {
            int erro = listar(tarefas, pos);

        }else if (opcao == 0) {
            printf("Sair\n");
        }else {
            printf("opcao invalida");
        }
        
    } while(opcao != 0);  
}