#include <stdio.h>

extern char **environ;

int main(int argc, char **argv, char **env)
{
    printf("Adresse de env     : %p\n", (void *)&env);
    printf("Adresse de environ : %p\n", (void *)&environ);

    return 0;
}
