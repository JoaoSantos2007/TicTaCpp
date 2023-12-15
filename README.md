# TicTaCpp - Jogo da Velha em C++

## Descrição
TicTaCpp é uma implementação simples do clássico jogo da velha (Tic Tac Toe) desenvolvida em C++. Este jogo pode ser jogado na linha de comando.

## Funcionalidades
- Jogo da velha em C++ para 2 jogadores.
- Interface simples na linha de comando para interação.

## Requisitos do Sistema
- Compilador C++ (suporte para C++11 ou superior)
- Terminal ou prompt de comando para executar o jogo

## Como Compilar e Executar
1. Abra um terminal/prompt de comando.
2. Navegue até o diretório onde os arquivos do jogo estão localizados.
3. Compile o jogo usando um compilador C++ compatível com C++11 ou superior:
    ```bash
    g++ main.cpp -o TicTaCpp
    ```
4. Para executar o jogo, use o comando:
    ```bash
    ./TicTaCpp
    ```

## Como Jogar
- O jogo da velha é jogado em um tabuleiro 3x3.
- Cada jogador, alternadamente, escolhe uma posição para marcar com 'X' ou 'O'.
- O objetivo é formar uma linha, coluna ou diagonal com suas marcações.
- O primeiro jogador a conseguir isso é o vencedor.

## Estrutura do Código
- `main.cpp`: Contém o código principal do jogo.

## Exemplo de Uso
```
=================
  Jogo da Velha  
=================

[1][2][3]
[4][5][6]
[7][8][9]

Player 1 digite onde voce quer colocar X: 5

=================
  Jogo da Velha  
=================

[1][2][3]
[4][X][6]
[7][8][9]

...

X ganhou a partida!

Quer jogar mais uma partida[s/n]: n
```

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para fazer um fork do projeto e enviar pull requests com melhorias.

## Autor
João Pedro Tomaz dos Santos - [JoaoSantos2007](https://github.com/JoaoSantos2007)

## Licença
Este projeto está licenciado sob a [Licença MIT](LICENSE).
