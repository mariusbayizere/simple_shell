#include "shell.h"

/**
 * deallocation - Deallocate memory and set the pointer to NULL
 * @alf: Pointer to a pointer to the memory to be deallocated
 * Return: 1 if memory deallocation was successful.
 */
int deallocation(void **alf)
{
	if (alf && *alf)
	{
		free(*alf);
		*alf = NULL;
		return (1);
	}
	return (0);
}
