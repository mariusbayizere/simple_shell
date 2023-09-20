#include "shell.h"

char **string_array_copy(variable *file);
int XXintilializedXX(variable *file, char *var, char *value);
int xxremove_enviromentXX(variable *file, char *var);
char **string_array_copy(variable *file);

/**
 * xxremove_enviromentXX - Remove nodes from a linked list based on a variable
 * @file: Pointer to the file structure containing the linked list
 * @var: Pointer to the variable to match for removal
 * Return: The number of nodes removed from the list.
 */
int xxremove_enviromentXX(variable *file, char *var)
{
	type *queue = file->pwd;
	size_t x = 0;
	char *al;

	if (!queue || !var)
		return (0);

	while (queue)
	{
		al = viewing_defff(queue->data, var);
		if (al && *al == '=')
		{
			file->maxx = delete_node_at_index(&(file->pwd), x);
			x = 0;
			queue = file->pwd;
			continue;
		}
		queue = queue->next;
		x++;
	}
	return (file->maxx);
}
/**
 * string_array_copy - Copy and return a string array.
 * @file: A pointer to a variable struct containing environment information.
 * Return: A pointer to the copied string array.
 */
char **string_array_copy(variable *file)
{
	if (!file->environ || file->maxx)
	{
		file->environ = xString_information(file->pwd);
		file->maxx = 0;
	}

	return (file->environ);
}

/**
 * XXintilializedXX - Initialize or update a variable in a linked list.
 * @file: A pointer to a variable containing a linked list.
 * @var: The name of the variable to initialize or update.
 * @value: The value to assign to the variable.
 * Return: 0 on success, 1 if memory allocation fails.
 */
int XXintilializedXX(variable *file, char *var, char *value)
{
	char *size = NULL;
	type *queue;
	char *al;

	if (!var || !value)
		return (0);

	size = malloc(lengtht_string(var) + lengtht_string(value) + 2);
	if (!size)
		return (1);
	coping_string(size, var);
	concatineting_strings(size, "=");
	concatineting_strings(size, value);
	queue = file->pwd;
	while (queue)
	{
		al = viewing_defff(queue->data, var);
		if (al && *al == '=')
		{
			free(queue->data);
			queue->data = size;
			file->maxx = 1;
			return (0);
		}
		queue = queue->next;
	}
	putting_head_last(&(file->pwd), size, 0);
	free(size);
	file->maxx = 1;
	return (0);
}
