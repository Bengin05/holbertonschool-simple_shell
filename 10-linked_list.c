#include <string.h>
#include <stdlib.h>

extern char **environ;

typedef struct s_path
{
	char *dir;
	struct s_path *next;
} t_path;

t_path *linked_list(const char *name)
{
	int i = 0;
	size_t len;
	char *path_copy;
	char *start;
	char *end;
	t_path *head = NULL;
	t_path *current = NULL;
	t_path *node;

	if (name == NULL)
		return (NULL);

	len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0 &&
		    environ[i][len] == '=')
		{
			path_copy = strdup(environ[i] + len + 1);
			if (path_copy == NULL)
				return (NULL);
			break;
		}
		i++;
	}
	if (environ[i] == NULL)
		return (NULL);

	start = path_copy;
	while (*start)
	{
		end = start;
		while (*end && *end != ':')
			end++;

		node = malloc(sizeof(t_path));
		if (node == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		node->dir = malloc((end - start) + 1);
		if (node->dir == NULL)
		{
			free(node);
			free(path_copy);
			return (NULL);
		}
		strncpy(node->dir, start, end - start);
		node->dir[end - start] = '\0';
		node->next = NULL;

		if (head == NULL)
			head = node;
		else
			current->next = node;
		current = node;
		if (*end == ':')
			start = end + 1;
		else
			start = end;
	}
	free(path_copy);
	return (head);
}
