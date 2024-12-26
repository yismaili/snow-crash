#include <stdio.h>
int main(int ac, char **av)
{
    int i = 0;
    if (ac != 2)
    {
        printf("You need to provied only one arg.\n");
        return 1;
    }
    while (av[1][i])
    {
        printf("%c", av[1][i] - i);
        i++;
    }
    printf("\n");
    return 0;
}