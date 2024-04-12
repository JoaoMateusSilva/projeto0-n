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
    printf("4 - Exportar\n");
    printf("0 - Sair\n");
    
    printf("Entre com uma opcao: ");
    int i = scanf("%d", &opcao);
    clearBuffer();
    
    printf("Opcao escolhida: %d\n", opcao);
    
    if (opcao == 1) {
      erro = criar(tarefas, &pos);
      if(erro == MAX_TAREFA)
        printf("maximo de tarefas alcancadas\n");
      else if(erro == NUMERO_INVALIDO)
        printf("prioridade invalida\n");
    } else if (opcao == 2) {
      erro = deletar(tarefas, &pos);
      if(erro == SEM_TAREFAS)
        printf("sem tarefas para deletar\n");
      else if(erro == NAO_ENCONTRADO)
        printf("tarefa nao existe\n");
    } else if (opcao == 3) {
      erro = listar(tarefas, &pos);
      if(erro == SEM_TAREFAS)
        printf("sem tarefas para listar\n");
    } else if (opcao == 0) {
      printf("Sair. . .\n");
      erro = salvar(tarefas, &pos);
      if(erro == ABRIR)
        printf("erro ao abrir o arquivo\n");
      else if(erro == FECHAR)
        printf("erro ao fechar o arquivo\n");
      else if(erro == ESCREVER)
        printf("erro ao escrever no arquivo\n");
    } else if (opcao == 4) {
        erro = exportar(tarefas, &pos);
        if(erro == ABRIR)
          printf("erro ao abrir o arquivo\n");
    } else {
      printf("opcao invalida");
    }
  } while (opcao != 0);

    ERROS errosalvar = fs[3](tarefas, &pos);
    if(erro == ABRIR)
        printf("erro ao abrir o arquivo\n");
    else if(erro == FECHAR)
        printf("erro ao fechar o arquivo\n");
    else if(erro == ESCREVER)
        printf("erro ao escrever no arquivo\n");
}
