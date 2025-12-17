#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_line(const char *str, int *count)
{
        char **words = NULL;
        char *token;
        int i = 0;

        if (str == NULL)
        {
                *count = 0;
                return (NULL);
        }
        token = strtok((char *)str, " \t\n");

        while (token != NULL)
        {
                char **tmp = realloc(words, sizeof(char *) * (i + 1));

                if (tmp == NULL)
                {
                        for (int j = 0; j < i; j++)
                                free(words[j]);

                        free(words);
                        *count = 0;
                        return (NULL);
                }
                words = tmp;
                words[i] = strdup(token);

                if (words[i] == NULL)
                {
                        for (int j = 0; j < i; j++)
                                free(words[j]);
                        free(words);
                        *count = 0;
                        return (NULL);
                }
                i++;
                token = strtok(NULL, " \t\n");
        }
        *count = i;
        return (words);
}

int main(void) {
    // your code here
    return 0;
}
