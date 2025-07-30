#include <stdio.h>

int main (void)
{
    char p[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    printf("a  b  c\n");
    printf("1 %c %c %c\n", p[0][0], p[0][1], p[0][2]);
    printf("2 %c %c %c\n", p[1][0], p[1][1], p[1][2]);
    printf("3 %c %c %c\n", p[2][0], p[2][1], p[2][2]);
}