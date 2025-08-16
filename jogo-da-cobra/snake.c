#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 25
#define LENGTH 60

int create_field(char m[HEIGHT][LENGTH]);

int main(void)
{
    // criar campo inicial com quantidade de caracteres HEIGHT e LENGHT '.' e '#'.
    char m[HEIGHT][LENGTH];
    create_field(m);

    int half_height = HEIGHT / 2;
    int half_length = LENGTH / 2;

    m[half_height][half_length] = 'S';

    while(true)
    {
        // mostre na tela a saída do campo.
        for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < LENGTH; j++)
            {
                printf("%c", m[i][j]);
            }
            printf("\n");
        }

        

        usleep(500000);
        system("clear");

    }
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