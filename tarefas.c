#include "tarefas.h"
#include <stdio.h>
#include <string.h>

ERROS criar(Tarefa tarefas[], int *pos) {
  if (*pos >= TOTAL)
    return MAX_TAREFA;

  printf("Entre com a prioridade: ");
  scanf("%d", &tarefas[*pos].prioridade);

  if (tarefas[*pos].prioridade < 1 || tarefas[*pos].prioridade > 10)
    return NUMERO_INVALIDO;

  clearBuffer();

  printf("Entre com a categoria: ");
  fgets(tarefas[*pos].categoria, CATEGORIA, stdin);
  tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0';
  
  printf("Entre com a descricao: ");
  fgets(tarefas[*pos].descricao, DESCRICAO, stdin);
  tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0';

  *pos = *pos + 1;
  return OK;
}

ERROS deletar(Tarefa tarefas[], int *pos) {
  if (*pos == 0)
    return SEM_TAREFAS;

  int pos_deletar;

  printf("Entre com a posicao da tarefa a ser deletada: ");
  scanf("%d", &pos_deletar);

  pos_deletar--;
  if (pos_deletar >= *pos || pos_deletar < 0)
    return NAO_ENCONTRADO;

  for (int i = pos_deletar; i < *pos; i++) {
    tarefas[i].prioridade = tarefas[i + 1].prioridade;
    strcpy(tarefas[i].categoria, tarefas[i + 1].categoria);
    strcpy(tarefas[i].descricao, tarefas[i + 1].descricao);
  }

  *pos = *pos - 1;

  return OK;
}

ERROS listar(Tarefa tarefas[], int *pos) {
  int opcao;
  printf("Escolha uma opcao:\n");
  printf("1. Mostrar todas as tarefas\n");
  printf("2. Procurar por categoria\n");
  printf("Sua escolha: ");
  scanf("%d", &opcao);

  if (opcao == 1) {
    if (*pos == 0)
      return SEM_TAREFAS;

    for (int i = 0; i < *pos; i++) {
      printf("Pos: %d\t", i + 1);
      printf("Prioridade: %d\t", tarefas[i].prioridade);
      printf("Categoria: %s\t", tarefas[i].categoria);
      printf("Descricao: %s\n", tarefas[i].descricao);
    }
  } else if (opcao == 2) {
    char categoria_pesquisar[CATEGORIA];
    printf("Entre com a categoria a ser pesquisada: ");
    scanf("%s", categoria_pesquisar);

    int categoria_encontrada = 0;
    if (strlen(categoria_pesquisar) == 0) {
      for (int i = 0; i < *pos; i++) {
        printf("Pos: %d\t", i + 1);
        printf("Prioridade: %d\t", tarefas[i].prioridade);
        printf("Categoria: %s\t", tarefas[i].categoria);
        printf("Descricao: %s\n", tarefas[i].descricao);
      }
    } else {
      for (int i = 0; i < *pos; i++) {
        if (strcmp(tarefas[i].categoria, categoria_pesquisar) == 0) {
          printf("Pos: %d\t", i + 1);
          printf("Prioridade: %d\t", tarefas[i].prioridade);
          printf("Categoria: %s\t", tarefas[i].categoria);
          printf("Descricao: %s\n", tarefas[i].descricao);
          categoria_encontrada = 1;
        }
      }

      if (!categoria_encontrada)
        printf("Categoria nao encontrada.\n");
    }
  }

  return OK;
}
ERROS salvar(Tarefa tarefas[], int *pos) {
  FILE *f = fopen("tarefas.bin", "wb");
  if (f == NULL)
    return ABRIR;

  int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
  if (qtd == 0)
    return ESCREVER;

  qtd = fwrite(pos, 1, sizeof(int), f);
  if (qtd == 0)
    return ESCREVER;

  if (fclose(f))
    return FECHAR;

  return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos) {
  FILE *f = fopen("tarefas.bin", "rb");
  if (f == NULL)
    return ABRIR;

  int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
  if (qtd == 0)
    return LER;

  qtd = fread(pos, 1, sizeof(int), f);
  if (qtd == 0)
    return LER;

  if (fclose(f))
    return FECHAR;

  return OK;
}

ERROS exportar(Tarefa tarefas[], int *pos) {
    if (*pos == 0)
        return SEM_TAREFAS;

    char nome_arquivo[100];
    printf("Entre com o nome do arquivo para exportar: ");
    fgets(nome_arquivo, 100, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';
  
    FILE *f = fopen(nome_arquivo, "w");
    if (f == NULL)
        return ABRIR;

    if (f == NULL) {
        return ABRIR;
    }

    for (int i = 0; i < *pos; i++) {
        fprintf(f, "Prioridade: %d, Categoria: %s, Descricao: %s\n",tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].descricao);
    }
    fclose(f);

    return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
