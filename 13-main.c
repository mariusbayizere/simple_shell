#include "shell.h"

/**
 * displaing_out_element - Display elements of a linked list with formatting
 * @mkd: Pointer to the head of the linked list to be displayed
 * Return: The number of nodes processed in the linked list.
 */
size_t displaing_out_element(const type *mkd)
{
	size_t x = 0;

	while (mkd)
	{
		dusplaying_chaaracter(change_string_number_(mkd->terry, 10, 0));
		_putchar(':');
		_putchar(' ');
		dusplaying_chaaracter(mkd->data ? mkd->data : "(nil)");
		dusplaying_chaaracter("\n");
		mkd = mkd->next;
		x++;
	}
	return (x);
}
/**
 * measure_linked_list - Measure the length of a linked list
 * @fg: Pointer to the head of the linked list to be measured
 * Return: The number of nodes in the linked list.
 */
size_t measure_linked_list(const type *fg)
{
	size_t x = 0;

	while (fg)
	{
		fg = fg->next;
		x++;
	}
	return (x);
}

/**
 * searching_element - Search for a specific element in a linked list
 * @nodes: Pointer to the head of the linked list to be searched
 * @queue: Pointer to the element to be searched
 * Return: The index of the found element.
 */
ssize_t searching_element(type *nodes, type *queue)
{
	size_t x = 0;

	while (nodes)
	{
		if (nodes == queue)
			return (x);
		nodes = nodes->next;
		x++;
	}
	return (-1);
}

/**
 * xString_information - Convert linked list of strings to an array of strings
 * @nodes: Pointer to the head of the linked list containing strings
 * Return: A dynamically allocated array of strings.
 */
char **xString_information(type *nodes)
{
	type *queue = nodes;
	size_t x = measure_linked_list(nodes), y;
	char **chrs;
	char *data;

	if (!nodes || !x)
		return (NULL);
	chrs = malloc(sizeof(char *) * (x + 1));
	if (!chrs)
		return (NULL);
	for (x = 0; queue; queue = queue->next, x++)
	{
		data = malloc(lengtht_string(queue->data) + 1);
		if (!data)
		{
			for (y = 0; y < x; y++)
				free(chrs[y]);
			free(chrs);
			return (NULL);
		}

		data = coping_string(data, queue->data);
		chrs[x] = data;
	}
	chrs[x] = NULL;
	return (chrs);
}

/**
 * linked_list_nodesx - Search for a node in a linked list based on criteria
 * @queue: Pointer to the head of linked list
 * @files_d: String used as a search criterion
 * @str: Character used as an additional search criterion
 * Return: A pointer to the first node
 */
type *linked_list_nodesx(type *queue, char *files_d, char str)
{
	char *al = NULL;

	while (queue)
	{
		al = viewing_defff(queue->data, files_d);
		if (al && ((str == -1) || (*al == str)))
			return (queue);
		queue = queue->next;
	}
	return (NULL);
}
