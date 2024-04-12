#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos){ //nessa função é possível criar tarefas, se o número de tarefas for menor que o TOTAL que é igual a 100.
    if(*pos >= TOTAL)//aqui realiza a verificação se a posição excede ou é igual ao total,caso for retornará MAX_TAREFA, pois não há como criar mais tarefas.
        return MAX_TAREFA;

    printf("Entre com a prioridade: "); //se for possível criar uma tarefa, você terá que fornecer 3 informações: a prioridade, a categoria e a descrição.
    scanf("%d", &tarefas[*pos].prioridade,); //na prioridade o úsuario fornece um número para demonstrar o quanto a tarefa é importante.
    
    if(tarefas[*pos].prioridade < 1 || tarefas[*pos].prioridade > 10) 
        return NUMERO_INVALIDO;
    
    clearBuffer();                              //na categoria o úsuario pode escrever até um máximo de 100 caracteres.
    
    printf("Entre com a categoria: ");          //e por fim na descrição o úsuario pode escrever no máximo 300 caracteres.
    fgets(tarefas[*pos].categoria, CATEGORIA, stdin);  //tudo isso é realizado para a criação de uma tarefa.
    tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0';
    clearBuffer();
    
    printf("Entre com a descricao: ");
    fgets(tarefas[*pos].descricao, DESCRICAO, stdin);
    tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao, "\n")] = '\0';
    clearBuffer();
    
    *pos = *pos + 1; //aqui a posição é somada com 1 para quando salvar uma tarefa essa tarefa não salve na posição de outra tarefa e a substitua.
    //assim cada tarefa tem sua posição única.
    return OK; //caso o código não dê nenhum erro é retornado OK.
}

ERROS deletar(Tarefa tarefas[], int *pos){ //nessa função é possível deletar tarefas se existirem tarefas e se o número da posição da tarefa fornecido equivaler a uma tarefa.
    if(*pos == 0) //aqui realiza a verificação se existem tareafas, caso não exista, retornará SEM_TAREFAS.
        return SEM_TAREFAS; 
    
    int pos_deletar; 
    
    printf("Entre com a posicao da tarefa a ser deletada: "); //é solicitado ao úsuario escolher a posição da tarefa que deseja deletar, se ela não existir o programa retoranará NAO_ENCONTRADO.
    scanf("%d", &pos_deletar); 
    
    pos_deletar--; // garante a posição certa no array.
    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){ //caso a tarefa exista em determinada posição ela é deletada todos os comando necessários para isso estão dentro do for.
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);
    }

    *pos = *pos - 1; //aqui acerta a posição de todas as tarefas já que uma foi removida é necessário tirar 1 da posição para que tudo fique certo.

    return OK; //caso a função funcione corretamente sem o retorno de erros ela retornará OK.
}

ERROS listar(Tarefa tarefas[], int *pos){ //nessa função é possível verificar as tarefas criadas pelo úsuario
    if(*pos == 0)
        return SEM_TAREFAS; //aqui verifica se existem tarefas para listar, se não existir a função retornará SEM_TAREFAS.

    for(int i=0; i<*pos; i++){ //esse for é utilizado para exibir as iformações sobre a tarefa no caso são: a posição, a prioridade, a categoria e a descrição.
        printf("Pos: %d\t", i+1);
        printf("Prioridade: %d\t", tarefas[i].prioridade);
        printf("Categoria: %s\t", tarefas[i].categoria);
        printf("Descricao: %s\n", tarefas[i].descricao);
    }

    return OK; //caso tudo funcione de acordo é retornado um OK
}

ERROS salvar(Tarefa tarefas[], int *pos){ //essa função não é disponibilizada para o úsuario mas tem a função de salvar as tarefas em binários após o úsuario sair do programa.
    FILE *f = fopen("tarefas.bin", "wb"); //abre o tarefa.bin para escrita.
    if(f == NULL) //aqui verifica se há um problema em abrir o arquivo, se houver retorna ABRIR.
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);//escreve a tarefa.
    if(qtd == 0)
        return ESCREVER; //aqui verifica se há um problema em escrever o arquivo, se houver retorna ESCREVER.

    qtd = fwrite(pos, 1, sizeof(int), f);//escreve a posição
    if(qtd == 0)
        return ESCREVER; //aqui verifica se há um problema em escrever a posição da tarefa, se houver retorna ESCREVER de novo.

    if(fclose(f)) //fecha o arquivo
        return FECHAR; //por último aqui retorna FECHAR se houver um problema na hora de fechar o arquivo.

    return OK; //caso tudo dê certo é retornado um OK.
}

ERROS carregar(Tarefa tarefas[], int *pos){ //essa função também não é disponibilizada pelo úsuario e é reponsável por carregar as tarefas quando o programa é iniciado.
    FILE *f = fopen("tarefas.bin", "rb"); //simplismente abre o arquivo tarefas.bin para leitura.
    if(f == NULL) //caso tenha problemas na hora de abrir o arquivo é retornado ABRIR.
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f); //lê todas as terefas no arquivo.
    if(qtd == 0)
        return LER; //retorna o LER caso tenha problema em ler as tarefas.

    qtd = fread(pos, 1, sizeof(int), f);//lê a posição das tarefas.
    if(qtd == 0)
        return LER;//retorna LER caso tenha um erro em ler as posições das tarefas.

    if(fclose(f))//fecha o arquivo.
        return FECHAR; //retorna FECHAR se houver um erro na hora de fechar o arquivo.

    return OK; //caso tudo dê certo retorna ok.

}

void clearBuffer(){ // nessa função é possível limpar o buffer do teclado e é utilizada na hora de criar tarefas.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
