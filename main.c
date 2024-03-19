#include <stdio.h>

int main(){
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
    } while(opcao != 0);  
}