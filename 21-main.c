#include "shell.h"

/**
 * exchange_specific_variable - Exchange specific variables
 * in an array of strings
 * @file: Pointer to the 'variable' structure for data storage
 * Return: 0 on success, no return value on failure.
 */
int exchange_specific_variable(variable *file)
{
	int x = 0;
	type *queue;

	for (x = 0; file->n[x]; x++)
	{
		if (file->n[x][0] != '$' || !file->n[x][1])
			continue;

		if (!compare_two_string(file->n[x], "$?"))
		{
			exchnge_character(&(file->n[x]),
					Duplicating_string(change_string_number_(file->status, 10, 0)));
			continue;
		}
		if (!compare_two_string(file->n[x], "$$"))
		{
			exchnge_character(&(file->n[x]),
					Duplicating_string(change_string_number_(getpid(), 10, 0)));
			continue;
		}
		queue = linked_list_nodesx(file->pwd, &file->n[x][1], '=');
		if (queue)
		{
			exchnge_character(&(file->n[x]),
					Duplicating_string(Xfinding_single_charcterX(queue->data, '=') + 1));
			continue;
		}
		exchnge_character(&file->n[x], Duplicating_string(""));

	}
	return (0);
}
/**
 * current_chacter - Handle special characters in a command string
 *
 * @file: Pointer to the 'variable' structure for data storage
 * @size: Pointer to a character string representing a command
 * @al: Pointer to a size_t variable to keep track of the current position
 * Return: 1 if a special character is found.
 */
int current_chacter(variable *file, char *size, size_t *al)
{
	size_t y = *al;

	if (size[y] == '|' && size[y + 1] == '|')
	{
		size[y] = 0;
		y++;
		file->munas = PATH;
	}
	else if (size[y] == '&' && size[y + 1] == '&')
	{
		size[y] = 0;
		y++;
		file->munas = HISTSIZE;
	}
	else if (size[y] == ';')
	{
		size[y] = 0;
		file->munas = COMMAND;
	}
	else
		return (0);
	*al = y;
	return (1);
}
/**
 * exchange_token - Exchange a token in the variable's n[0]
 * with values from sahar
 *
 * @file: Pointer to the 'variable' structure that contains data storage.
 *
 * Return: 1 if the exchange is successful
 */
int exchange_token(variable *file)
{
	char *al;
	type *queue;
	int x;

	for (x = 0; x < 10; x++)
	{
		queue = linked_list_nodesx(file->sahar, file->n[0], '=');
		if (!queue)
			return (0);
		free(file->n[0]);
		al = Xfinding_single_charcterX(queue->data, '=');
		if (!al)
			return (0);
		al = Duplicating_string(al + 1);
		if (!al)
			return (0);
		file->n[0] = al;
	}
	return (1);
}

/**
 * exchnge_character - Exchange a character pointer with a new one
 * @begin: Pointer to a character pointer that will be replaced.
 * @end:   The new character pointer to replace.
 * Return: 1 if the exchange was successful, 0 otherwise.
 */
int exchnge_character(char **begin, char *end)
{
	free(*begin);
	*begin = end;
	return (1);
}


/**
 * manipulation_variable - Manipulate variable based
 * on file->munas and file->status
 * @file: Pointer to the structure for data storage.
 * @size: Pointer to a character array that may be modified.
 * @al: Pointer to a size_t variable that may be modified.
 * @ol: Old value of 'al'.
 * @sizex: Size to set to if certain conditions are met.
 * Return: void
 */
void manipulation_variable(variable *file, char *size,
		size_t *al, size_t ol, size_t sizex)
{
	size_t y = *al;

	if (file->munas == HISTSIZE)
	{
		if (file->status)
		{
			size[ol] = 0;
			y = sizex;
		}
	}
	if (file->munas == PATH)
	{
		if (!file->status)
		{
			size[ol] = 0;
			y = sizex;
		}
	}

	*al = y;
}
