#include "shell.h"

/**
 * wood_tails - Create and add a new node to the beginning of a linked list
 *
 * @nodes: Pointer to a pointer to the linked list
 * @data: Data to be stored in the new node
 * @terry: Integer value to be assigned to member of the new node
 * Return: A pointer to the newly created.
 */
type *wood_tails(type **nodes, const char *data, int terry)
{
	type *cahill;

	if (!nodes)
		return (NULL);
	cahill = malloc(sizeof(type));
	if (!cahill)
		return (NULL);
	block_memory((void *)cahill, 0, sizeof(type));
	cahill->terry = terry;
	if (data)
	{
		cahill->data = Duplicating_string(data);
		if (!cahill->data)
		{
			free(cahill);
			return (NULL);
		}
	}
	cahill->next = *nodes;
	*nodes = cahill;
	return (cahill);
}


/**
 * Deleting_all_element - Free memory and clear a linked list
 * @peeks: Pointer to a pointer to the head of the linked list
 * Return: None (void function).
 */
void Deleting_all_element(type **peeks)
{
	type *queue, *next_node, *nodes;

	if (!peeks || !*peeks)
		return;
	nodes = *peeks;
	queue = nodes;
	while (queue)
	{
		next_node = queue->next;
		free(queue->data);
		free(queue);
		queue = next_node;
	}
	*peeks = NULL;
}

/**
 * displaying_out_linkedlist - Display the contents of a linked list
 * @fg: Pointer to the head of the linked list to be displayed
 * Return: The number of nodes processed in the linked list.
 */
size_t displaying_out_linkedlist(const type *fg)
{
	size_t x = 0;

	while (fg)
	{
		dusplaying_chaaracter(fg->data ? fg->data : "(nil)");
		dusplaying_chaaracter("\n");
		fg = fg->next;
		x++;
	}
	return (x);
}

/**
 * delete_node_at_index - Delete a node from a linked list at a specified index
 * @nodes: Pointer to a pointer to the head of the linked list
 * @pr: Index of the node to be deleted
 * Return: 1 if the node is successfully.
 */
int delete_node_at_index(type **nodes, unsigned int pr)
{
	type *queue, *current;
	unsigned int x = 0;

	if (!nodes || !*nodes)
		return (0);

	if (!pr)
	{
		queue = *nodes;
		*nodes = (*nodes)->next;
		free(queue->data);
		free(queue);
		return (1);
	}
	queue = *nodes;
	while (queue)
	{
		if (x == pr)
		{
			current->next = queue->next;
			free(queue->data);
			free(queue);
			return (1);
		}
		x++;
		current  = queue;
		queue = queue->next;
	}
	return (0);
}

/**
 * putting_head_last - Add a new node to the end of a linked list
 * @nodes: Pointer to a pointer to the head of the linked list
 * @data: Data to be stored in the new node
 * @terry: Integer value to be assigned to member of the new node
 * Return: A pointer to the newly created node.
 */
type *putting_head_last(type **nodes, const char *data, int terry)
{
	type *diaz, *queue;

	if (!nodes)
		return (NULL);

	queue = *nodes;
	diaz = malloc(sizeof(type));
	if (!diaz)
		return (NULL);
	block_memory((void *)diaz, 0, sizeof(type));
	diaz->terry = terry;
	if (data)
	{
		diaz->data = Duplicating_string(data);
		if (!diaz->data)
		{
			free(diaz);
			return (NULL);
		}
	}
	if (queue)
	{
		while (queue->next)
			queue = queue->next;
		queue->next = diaz;
	}
	else
		*nodes = diaz;
	return (diaz);
}
