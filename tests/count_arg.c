#include <stdio.h>

int main(int argc, char **argv)
{
    printf("%d\n", argc);
    int i = i;
    while(argv[i])
    {
        printf("%s\n", argv[i]);
        i++;
    }
    return 0;
}