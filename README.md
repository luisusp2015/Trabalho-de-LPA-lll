# Trabalho-de-LPA-lll

# readme-geral-



1º) Alunos: Luís Felipe Moreira nºUsp(9312881), Matheus Campanini Mughrabi nºUsp(9312835), France Sutil de Aguiar nºusp(9312814)



2º) Detalhes técnicos: Os programas foram escritos em linguagem "C";
- Foram usadas as bibliotecas stdio.h e stdlib.h; - O compilador usado foi DEV-C++;Os programas foi contruindo em uma plataforma Win 8 - 64bits; - Os programas foram criados na forma de "aplicativo" para plataforma Windows;



3º) - Organização do projeto: - O projeto "Trabalho 3 de LPA" possui um programa que implementa operações em uma matriz esparsa, tais como a criação de uma matriz m por n, a exlusão da matriz, consulta dos valores de uma posição (i,j) da matriz, entre outras operações que estão melhor detalhas no guia do programa.



4º) Visão geral do funcionamento do programa (mais detalhes estão contidos dentro da pasta do programa): O programa funciona inicialmente com a criação de uma matriz esparsa, a qual é possível com a utilização de duas "structs" (uma lista encadeada e uma árvore), por meio de uma função chamada "criadordematriz".
O programa é capaz de realizar buscas nos membros da matriz por meio da função "buscadordemembro", que recebe como argumentos uma estrutura na forma de ponteiro e duas variáveis inteiros, então ele busca busca a linha correta do membro por meio de um ciclo while, então o programa devolve a mensagem "o valor membro buscado eh 0", caso o membro não seja encontrado por meio do comando "if". Caso o membro seja encontrado, o programa busca a coluna do membro por meio de um comando "if" que contém um ciclo "while" e outro comando "if".
O programa também realiza a soma dos membros de uma coluna por meio da função "somacoluna", que recebe como argumento um struct na forma de ponteiro e uma variável inteira, então por meio de três ciclos "while" e um comando "if, o programa realiza a soma dos membros da coluna, retornando o valor por meio do comando printf. 
O programa também é capaz de realizar a exclusão da matriz, por meio da função "excluimatriz", que se baseia do comando "free" para excluí-la, além de retornar a mensagem "a matriz foi exluída com sucesso".
