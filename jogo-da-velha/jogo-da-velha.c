/* É esperado que eu refaça esse código e melhore as funcionalidades,
tornando-o o mais eficiente. Não está completo e não é jogável.*/

#include <stdio.h>
#include <string.h>

int calc(char p[], int move, char player[]);

int main (void)
{
    // váriaveis criadas na memória.
    char p[9];
    int end = 0;
    int limit = 0;
    int move = 0;
    
    // adiciona um ponto em cada posição do jogo da velha.
    for (int i = 0; i < 9; i++)
    {
            p[i] = '.';
    }

    // escolha o jogador.
    printf("Qual jogador escolhido primeiro? o\\x\n");
    printf(": ");
    char player[2];
    scanf("%1s", &player);

    // verificar se escolha do jogador é válida
    if (player[0] != 'x' && player[0] != 'o')
    {
        printf("\nJogador inválido.\n\n");
        return 1;
    }

    while (true)
    {
        // mostre o jogo da velha.
        printf("%c %c %c\n", p[0], p[1], p[2]);
        printf("%c %c %c\n", p[3], p[4], p[5]);
        printf("%c %c %c\n", p[6], p[7], p[8]);

        printf("\n1a 1b 1c\n2a 2b 2c\n3a 3b 3c\n");
        printf(": ");

        // coloque a opção no buffer.
        char buff[3];
        scanf("%2s", &buff);

        // mude o jogo da velha para refletir a opção dada anteriormente.
        char n[9][3] = {"1a","1b","1c","2a","2b","2c","3a","3b","3c"};
        for (int i = 0; i < 9; i++)
        {
            if (strcmp(n[i], buff) == 0 && p[i] == '.')
            {
                p[i] = player[0];
            }
        }

        // caso alguém ganhe finalize o while com a variável end.
        end = calc(p, move, player);

        // verificação se alguém ganhou ou perdeu.
        if (end == 1)
        {
            printf("\n\n%c ganhou!\n", player[0]);
            break;
        }
        else if (move == 8)
        {
            printf("\n\nVocê empatou!\n");
            break;
        }

        // adicionar a quantidade de rodadas
        move++;

        // trocar o jogador
        if (player[0] == 'x')
        {
            player[0] = 'o';
        }
        else if (player[0] == 'o')
        {
            player[0] = 'x';
        }
    }
}

int calc(char p[], int move, char player[])
{
    if (move >= 4)
    {
        if ((p[0] == player[0] && p[1] == player[0] && p[2] == player[0]) ||
            (p[3] == player[0] && p[4] == player[0] && p[5] == player[0]) ||
            (p[6] == player[0] && p[7] == player[0] && p[8] == player[0]) ||

            (p[0] == player[0] && p[3] == player[0] && p[6] == player[0]) ||
            (p[1] == player[0] && p[4] == player[0] && p[7] == player[0]) ||
            (p[2] == player[0] && p[5] == player[0] && p[8] == player[0]) ||

            (p[0] == player[0] && p[4] == player[0] && p[8] == player[0]) ||
            (p[6] == player[0] && p[4] == player[0] && p[2] == player[0]))
            {
                return 1;
            }
    }
    return 0;
}
