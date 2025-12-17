#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        char *line = NULL;
        size_t len = 0;
        ssize_t nb_read;

        while (1)
        {
                printf("$ ");
                fflush(stdout);

                nb_read = getline(&line, &len, stdin);

                if (nb_read == -1)
                {
                        printf("\n");
                        break;
                }

                printf("%s", line);
        }

        free(line);
        return (0);
}
