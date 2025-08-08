/*
É esperado que eu refaça esse código e melhore as funcionalidades,
tornando-o o mais eficiente.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calc(char p[], char player);

int main (void)
{
    // váriaveis criadas na memória.
    char p[9];
    bool win = 0;
    int move = 0;
    bool stop_move = 0;
    bool found = 0;
    
    // adiciona um ponto em cada posição do jogo da velha. 0
    for (int i = 0; i < 9; i++)
    {
        p[i] = '.';
    }

    // escolha o jogador. 0
    printf("Qual jogador escolhido primeiro? [O/X]\n");
    printf("> ");
    char player;
    scanf("%1c", &player);
    getchar();
    player = toupper(player);

    // verificar se escolha do jogador é válida 0
    if (player != 'X' && player != 'O')
    {
        printf("\nJogador inválido.\n\n");
        return 1;
    }

    printf("\n");
    printf("1a │ 1b │ 1c\n");
    printf("───┼────┼───\n");
    printf("2a │ 2b │ 2c\n");
    printf("───┼────┼───\n");
    printf("3a │ 3b │ 3c\n");
    printf("\n");

    while (true)
    {
        // mostre o jogo da velha.
        printf("    a   b   c\n");
        printf("  ╔═══╤═══╤═══╗\n");
        printf("1 ║ %c │ %c │ %c ║\n", p[0], p[1], p[2]);
        printf("  ╟───┼───┼───╢\n");
        printf("2 ║ %c │ %c │ %c ║\n", p[3], p[4], p[5]);
        printf("  ╟───┼───┼───╢\n");
        printf("3 ║ %c │ %c │ %c ║\n", p[6], p[7], p[8]);
        printf("  ╚═══╧═══╧═══╝\n");

        // verificação se alguém ganhou ou perdeu.
        if (win == 1)
        {
            printf("\n");

           // trocar o jogador.
            if (player == 'X')
            {
                player = 'O';
            }
            else
            {
                player = 'X';
            }
            printf("%c ganhou!", player);
            printf("\n");
            return 0;
        }
        else if (move == 9)
        {
            printf("\n");
            printf("Vocês empataram!");
            printf("\n");
            return 0;
        }

        printf("> ");

        // coloque a opção no buffer.
        char buff[3];
        scanf("%2s", &buff);
        printf("\n");

        // tratar dados.
        if(isalpha(buff[0]))
        {
            char tmp;
            tmp = buff[0];
            buff[0] = buff[1];
            buff[1] = tmp;
        }

        if (isupper(p[1]))
        {
            buff[1] = tolower(buff[1]);
        }

        // mude o jogo da velha para refletir a opção dada anteriormente.
        char n[9][3] = {"1a","1b","1c","2a","2b","2c","3a","3b","3c"};

        stop_move = true;
        for (int i = 0; i < 9; i++)
        { 
            if (strcmp(n[i], buff) == 0 && p[i] == '.')
            {
                p[i] = player;
                stop_move = false;
                break;
            }
        }

        // caso alguém ganhe finalize o while com a variável end. 0
        if (move >= 4)
        {
            win = calc(p, player);
        }

        // trocar o jogador.
        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }

        // adicionar a quantidade de rodadas. 0
        if (stop_move == 0)
        {
            move++;
        }
        else
        {
            stop_move = 0;
        }
    }
    return 0;
}

int calc(char p[], char player)
{
    if ((p[0] == player && p[1] == player && p[2] == player) ||
        (p[3] == player && p[4] == player && p[5] == player) ||
        (p[6] == player && p[7] == player && p[8] == player) ||

        (p[0] == player && p[3] == player && p[6] == player) ||
        (p[1] == player && p[4] == player && p[7] == player) ||
        (p[2] == player && p[5] == player && p[8] == player) ||

        (p[0] == player && p[4] == player && p[8] == player) ||
        (p[6] == player && p[4] == player && p[2] == player))
        {
            return 1;
        }
    return 0;
}