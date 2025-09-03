#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define HEIGHT 25
#define LENGTH 60

int create_field(char m[HEIGHT][LENGTH]);
int move_snake(char m[HEIGHT][LENGTH], int *y, int *x);

int main(void)
{
    initscr();
    cbreak();
    noecho();

    // criar campo inicial com quantidade de caracteres HEIGHT e LENGHT '.' e '#'.
    char m[HEIGHT][LENGTH];
    create_field(m);

    // encontra meio do campo, para colocar cobra.
    int y = HEIGHT / 2;
    int x = LENGTH / 2;

    // colocar cobra.
    m[y][x] = 'S';

    while(true)
    {
        m[rand() % (HEIGHT * LENGTH)] = '*';

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

        move_snake(m, &y, &x);

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

int move_snake(char m[HEIGHT][LENGTH], int *y, int *x)
{
    int key = getch();
    int y_var, x_var;
    if (key == 'w')
    {
        y_var = - 1;
        x_var = 0;
    }
    else if (key == 'a')
    {
        y_var = 0;
        x_var = - 1;
    }
    else if (key == 's')
    {
        y_var = + 1;
        x_var = 0;
    }
    else if (key == 'd')
    {
        y_var = 0;
        x_var = + 1;
    }

    m[*y + y_var][*x + x_var] = m[*y][*x];
    m[*y][*x] = '.';
    *y += y_var;
    *x += x_var;

    return 0;
}
