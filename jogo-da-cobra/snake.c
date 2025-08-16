#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define HEIGHT 25
#define LENGTH 60

int create_field(char m[HEIGHT][LENGTH]);

int main(void)
{
    initscr();
    cbreak();
    noecho();

    // criar campo inicial com quantidade de caracteres HEIGHT e LENGHT '.' e '#'.
    char m[HEIGHT][LENGTH];
    create_field(m);

    int half_height = HEIGHT / 2;
    int half_length = LENGTH / 2;

    int tmp;

    int y = half_height;
    int x = half_length;

    m[half_height][half_length] = 'S';

    while(true)
    {
        // mostre na tela a saída do campo.
        for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < LENGTH; j++)
            {
                printw("%c", m[i][j]);
            }
            printw("\n");
        }

        refresh();

        int option = getch();
        if (option == 'w')
        {
            tmp = m[y][x];
            m[y - 1][x] = tmp;
            m[y][x] = '.';
            y = y - 1;
        }
        else if (option == 'a')
        {
            tmp = m[y][x];
            m[y][x - 1] = tmp;
            m[y][x] = '.';
            x = x - 1;
        }
        else if (option == 's')
        {
            tmp = m[y][x];
            m[y + 1][x] = tmp;
            m[y][x] = '.';
            y = y + 1;
        }
        else if (option == 'd')
        {
            tmp = m[y][x];
            m[y][x + 1] = tmp;
            m[y][x] = '.';
            x = x + 1;
        }
        clear();
    }
    endwin();
    return 0;
}

int create_field(char m[HEIGHT][LENGTH])
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == LENGTH - 1)
            {
                m[i][j] = '#';
            }
            else
            {
                m[i][j] = '.';
            }
        }
    }
    return 0;
}