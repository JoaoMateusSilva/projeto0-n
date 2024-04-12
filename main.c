#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, salvar, carregar}; //aqui é criado um array com as funções disponiveis para facilitar a chamada das mesmas.

    Tarefa tarefas[TOTAL]; //nesse array é definido como tamanho (TOTAL=100) de tarefas possíveis para criar.
    int pos;
    ERROS erro = fs[4](tarefas, &pos); //aqui é chamada a função carregar através do array criado anteriormente.
    if(erro != OK)
        pos = 0;

    int opcao; // as opções são escolhidas através de um numero inteiro que o úsuario digitar.
    do{
        printf("\nMenu principal\n"); //esses prints servem para mostrar ao úsuario as possíveis funções que ele pode executar nesse programa.
        printf("1 - Criar tarefa\n"); 
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: "); 

        scanf("%d", &opcao); //aqui pega a opção que o úsuario escolheu, que no caso tem que ser um número inteiro de 0 a 3.
        opcao--;
        if(opcao > 3)
            printf("Opcao invalida\n"); //caso o úsuario digite um número acima de 3 o retorno é dado como inválido.
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
    } while(opcao >= 0); //enquanto a opção for diferente de zero o programa irá repetir as etapas anteriores.

    fs[3](tarefas, &pos); //se a opção escolhida for a 0 o programa chamará função 3(salvar) e encerrará o programa.
}
