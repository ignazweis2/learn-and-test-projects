/* É esperado que eu refaça esse código e melhore as funcionalidades,
tornando-o o mais eficiente. Não está completo e não é jogável.*/

#include <stdio.h>
#include <string.h>

void player_position(char player, char buff[], int i, char n[][3], char p[])
int calc(char p[], move)

int main (void)
{
    // váriaveis criadas na memória.
    player[2] = {'X','O'};
    int end = 0;
    int limit = 0;
    char p[9];
    
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

    while (0)
    {
        // mostre o jogo da velha
        printf("%c %c %c\n", p[0], p[1], p[2]);
        printf("%c %c %c\n", p[3], p[4], p[5]);
        printf("%c %c %c\n", p[6], p[7], p[8]);

        printf("\n1a 1b 1c\n2a 2b 2c\n3a 3b 3c\n");
        printf(": ");

        // coloque a opção no buffer
        char buff[3];
        scanf("%2s", &buff);

        // mude o jogo da velha para refletir a opção dada anteriormente
        char n[9][3] = {"1a","1b","1c","2a","2b","2c","3a","3b","3c"};
        for (i = 0; i < 9; i++)
        {
            player_position(player, buff, i, n, p);
        }

        //caso alguém ganhe finalize o while com a variável end
        end = calc(p[], move);

        if (end == 1)
        {
            printf("%c ganhou!");
            break;
        }
        else if (move == 8)
        {
            printf("\n\nVocê empatou!\n");
            break;
        }

        move++;
    }
}

int calc(char p[], move)
{
    if (move = 4)
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
    }
}

void player_position(char player, char buff[], int i, char n[][3], char p[])
{
    if (strcmp(n[i], buff) == 0)
    {
        p[i] = player;
    }
}
