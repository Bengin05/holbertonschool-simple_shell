#include <stdio.h>
#include <unistd.h>

int main(void)
{
        printf("PPID = %d\n", getppid());
        return 0;
}
