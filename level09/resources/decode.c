#include <stdio.h>

int main(int ac, char **av)
{
    const char *encoded;
    int i = 0;

    if (ac != 2)
    {
        printf("You need to provied only one arg.\n");
        return 1;
    }

    encoded = av[1];

    while (encoded[i])
    {
        printf("%c", encoded[i] - i);
        i++;
    }
    printf("\n");
    return 0;
}