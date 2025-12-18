#include <string.h>
#include <stdlib.h>

extern char **environ;

typedef struct s_path
{
    char    *dir;
    struct s_path   *next;
} t_path;

t_path *linked_list(const char *name)
{
    int i = 0;
    size_t len;
    char *paty_copy;
    char *start;
    char *end;
    t_path *head = NULL;
    t_path *current = NULL;

    if (name == NULL)
        return (NULL);

    len = strlen(name);

        while (environ[i] != NULL)
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
        {
            paty_copy = strdup(environ[i] + len + 1);
            if (!paty_copy)
                return (NULL);
            break;
        }
        i++;
    }
    if (environ[i] == NULL)
        return NULL;

    start = paty_copy;
    while (*start)
    {
        end = start;
        while (*end && *end != ':')
            end++;
        
    }

    char *paty_copy = strdup(environ[i] + len + 1);
}