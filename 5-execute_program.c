#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int execute_program()
{
        pid_t pid = fork();

        for (int i = 0; i < 5; i++)
        {
                if (pid < 0)
                {
                        perror ("error fork");
                        exit (EXIT_FAILURE);
                }

                if (pid == 0)
                {
                        execlp ("ls", "ls", "-1", "/tmp", (char *) NULL);
                        perror ("error exec");
                        exit (EXIT_FAILURE);
                }

                else
                wait (NULL);
        }
                return (0);
}

int main(void)
{
        return 0;
}
