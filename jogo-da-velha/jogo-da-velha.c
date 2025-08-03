/* É esperado que eu refaça esse código e melhore as funcionalidades,
tornando-o o mais eficiente. Não está completo e não é jogável.*/

#include <stdio.h>

int calc(void);

int main (void)
{
    player[2] = {'X','O'};
    int completion = 0;
    char p[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    int limit = 0;

    while(completion)
    {
        printf("%c %c %c\n", p[0][0], p[0][1], p[0][2]);
        printf("%c %c %c\n", p[1][0], p[1][1], p[1][2]);
        printf("%c %c %c\n", p[2][0], p[2][1], p[2][2]);

        printf(":: letras são colunas, números são linhas\n");
        printf(":: a1,a2,a3,b1,b2,b3,c1,c2,c3");
        printf("Escolha uma posição: ");

        char buff[3];
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = '\0';

        limit++;

        completion = calc();
    }

    if(completion == 1)
    {
        printf("() You won\n", player);
    }
    

}

int calc(limit)
{
    if(limit == 6)
    {   
        if(p[0][0] == player && p[0][1] == player && p[0][2] == player) {return 1};
        if(p[1][0] == player && p[1][1] == player && p[1][2] == player) {return 1};
        if(p[2][0] == player && p[2][1] == player && p[2][2] == player) {return 1};

        if(p[0][0] == player && p[1][0] == player && p[2][0] == player) {return 1};
        if(p[0][1] == player && p[1][1] == player && p[2][1] == player) {return 1};
        if(p[0][2] == player && p[1][2] == player && p[2][2] == player) {return 1};

        if(p[0][0] == player && p[1][1] == player && p[2][2] == player) {return 1};
        if(p[2][0] == player && p[1][1] == player && p[0][2] == player) {return 1};
    }    
}

void player_position(player)
{
    if ("a1" == buff) {p[0][0] = player;}
    if ("a2" == buff) {p[1][0] = player;}
    if ("a3" == buff) {p[2][0] = player;}
    if ("b1" == buff) {p[0][1] = player;}
    if ("b2" == buff) {p[1][1] = player;}
    if ("b3" == buff) {p[2][1] = player;}
    if ("c1" == buff) {p[0][2] = player;}
    if ("c2" == buff) {p[1][2] = player;}
    if ("c3" == buff) {p[2][2] = player;}
}
