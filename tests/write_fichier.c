#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("historique.txt", O_RDWR);
    write(fd, "Test 2\n", 7);
    write(fd, "Test o\n", 7);
    return 0;
}