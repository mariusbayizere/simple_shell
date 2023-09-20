#include "shell.h"

int update_Alias_character(variable *file);
int _past_record(variable *file);
int dislaying_Alias(type *queue);
int remove_Al_character(variable *file, char *data);
int update_Alias_characterx(variable *file, char *data);
/**
 * update_Alias_character - Update an Alias character in the shell.
 * @file: A pointer to the variable representing the shell state.
 * Return: 0 on success, -1 on failure to update the Alias character.
 */
int update_Alias_character(variable *file)
{
	int x = 0;
	char *rib = NULL;
	type *queue = NULL;

	if (file->pin == 1)
	{
		queue = file->sahar;
		while (queue)
		{
			dislaying_Alias(queue);
			queue = queue->next;
		}
		return (0);
	}
	for (x = 1; file->n[x]; x++)
	{
		rib = Xfinding_single_charcterX(file->n[x], '=');
		if (rib)
			update_Alias_characterx(file, file->n[x]);
		else
			dislaying_Alias(linked_list_nodesx(file->sahar, file->n[x], '='));
	}

	return (0);
}
/**
 * remove_Al_character - Remove an Alias character from the shell.
 * @file: A pointer to the variable representing the shell state.
 * @data: A pointer to the Alias character to be removed.
 * Return: 0 on success, -1 on failure to remove the Alias character.
 */
int remove_Al_character(variable *file, char *data)
{
	int con;
	char *x, f;

	x = Xfinding_single_charcterX(data, '=');
	if (!x)
		return (1);
	f = *x;
	*x = 0;
	con = delete_node_at_index(&(file->sahar),
		searching_element(file->sahar, linked_list_nodesx(file->sahar, data, -1)));
	*x = f;
	return (con);
}

/**
 * _past_record - Record a past event or action in the shell.
 * @file: A pointer to the variable representing the shell state.
 * Return: 0 on success, -1 on failure to record the past event.
 */
int _past_record(variable *file)
{
	displaing_out_element(file->wallas);
	return (0);
}
/**
 * update_Alias_characterx - Update an Alias character in the shell.
 * @file: A pointer to the variable representing the shell state.
 * @data: A pointer to the new data to assign to the Alias character.
 * Return: 0 on success, -1 on failure to update the Alias character.
 */
int update_Alias_characterx(variable *file, char *data)
{
	char *al;

	al = Xfinding_single_charcterX(data, '=');
	if (!al)
		return (1);
	if (!*++al)
		return (remove_Al_character(file, data));

	remove_Al_character(file, data);
	return (putting_head_last(&(file->sahar), data, 0) == NULL);
}

/**
 * dislaying_Alias - Display Alias items stored in a queue.
 * @queue: A pointer to the queue containing Alias items.
 * Return: No return value.
 */
int dislaying_Alias(type *queue)
{
	char *al = NULL, *x = NULL;

	if (queue)
	{
		al = Xfinding_single_charcterX(queue->data, '=');
		for (x = queue->data; x <= al; x++)
		_putchar(*x);
		_putchar('\'');
		dusplaying_chaaracter(al + 1);
		dusplaying_chaaracter("'\n");
		return (0);
	}
	return (1);
}
