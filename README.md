# projeto0-n
Projeto que faz tarefas em C da aula de algoritmos 

<h1>Nomes e R.A</h1>
<h2>João Mateus E. B. da Silva 22.223.013-8 <br><br> Heron de Souza 22.223.009-6 </h2>
<br>

<h1>Sobre o Projeto</h1>
<p>
 Ele é um programa desenvolvido em C para a gestão e gerenciamento de tarefas, no qual um usuário pode criar, apagar, listar, guardar e carregar tarefas. Utiliza arquivos binários para guardar as tarefas e a sua posição atual. O vai permitir o usuário manter um registro controladamente organizado de suas atividades 
</p>

<h1>Propósito do Projeto</h1>
<p>
    O projeto consiste em  oferecer uma solução simples e eficiente para o gerenciamento, controlado pelo usuário, de tarefas atravez de um programa. Com ele, o usuário pode manter um registro organizado de suas atividades, facilitando o acompanhamento e a conclusão das tarefas.
</p>

<h1>O que está no Projeto</h1>
<p>
    O projeto é composto por três arquivos principais: 'main.c', 'tarefas.c' e 'tarefas.h'. O arquivo 'main.c' contém a função principal do programa, enquanto 'tarefas.c' contém as implementações das funções para manipulação das tarefas. O arquivo 'tarefas.h' contém as definições das estruturas e das assinaturas das funções utilizadas no programa.
</p> 

<h2>main.c</h2>
<p>
    O arquivo 'main.c' tem a função principal do programa. Nesse arquivo, é tarefado um array de funções fs, representando as diferentes operações que o usuário poderá realizar, como criação, delação, listagem, abraramento de afazeres ou afazeramentação. Ao mesmo tempo, um array de estruturas Tarefa é salvo de tudo, e uma variável pos é usada para controlar a principal desocorrência. . O programa entra em um loop que imprime um menu simples para o usuário chifrar a ociosidade atual. Portanto, a função fs[index] é relativa à opção do usuário.
</p>

<h2> <strong>tarefas.c</strong></h2>
<p>
    A parte de 'tarefas.c' ele vai ser o responsavel por possuir o codigo das implementações especificas, que vao manipular as tarefas, pois cada iten vai realizar uma operação diferente.
    <ul>
        <li>Função Criar: Permite ao usuário criar uma nova tarefa, fornecendo prioridade, categoria e descrição.</li>
        <li>Função Deletar: Permite ao usuário deletar uma tarefa existente, e informando a posição da tarefa que sera deletada.</li>
        <li>Função Listar:  Exibe ao usuário aLista de todas as tarefas criadas, exibindo sua prioridade, categoria e descrição.</li>
        <li>Função Salvar: Salva as tarefas e a posição atual no arquivo "tarefas.bin" para que possam ser carregadas posteriormente.</li>
        <li>Função Carregar: Carrega as tarefas e a posição salvas anteriormente no arquivo em binario "tarefas.bin".</li>
    </ul>
</p>

<h2>tarefas.h</h2>
<p>
   O arquivo tarefas.h é responsável por prover as definições básicas para o funcionamento do programa. Ele possui as estruturas de dados necessárias, como a estrutura Tarefa, que armazena informações importantes sobre cada tarefa, como a prioridade, categoria e descrição da tarefa. Além disso, o tarefas.h também dá firmeza à funcionalidade das funções que o programa utilizará, vulgo funções assinadas, indicando seus nomes, parâmetros necessários e tipos de retorno.
</p>
