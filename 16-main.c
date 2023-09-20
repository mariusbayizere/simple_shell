#include "shell.h"


/**
 * review_size_memory - Review and adjust size of dynamically allocated memory
 * @alf: Pointer to the previously allocated memory
 * @past_value: Previous size of the allocated memory
 * @Now_value: New size  for the memory allocation
 * Return: A pointer to the newly allocated memory .
 */
void *review_size_memory(void *alf, unsigned int past_value,
		unsigned int Now_value)
{
	char *al;

	if (!alf)
		return (malloc(Now_value));
	if (!Now_value)
		return (free(alf), NULL);
	if (Now_value == past_value)
		return (alf);

	al = malloc(Now_value);
	if (!al)
		return (NULL);

	past_value = past_value < Now_value ? past_value : Now_value;
	while (past_value--)
		al[past_value] = ((char *)alf)[past_value];
	free(alf);
	return (al);
}

/**
 * block_memory - Fill a character array with a specified character
 * @xx: Pointer to the character array to be filled
 * @q: Character to be used for filling
 * @arg: Number of times 'q' should be repeated
 * Return: A pointer to the character.
 */
char *block_memory(char *xx, char q, unsigned int arg)
{
	unsigned int x;

	for (x = 0; x < arg; x++)
		xx[x] = q;
	return (xx);
}

/**
 * delete_allocated_memory - Deallocate memory used by an array of strings
 * @xx: Pointer to an array of strings (char **)
 * Return: None (void)
 */
void delete_allocated_memory(char **xx)
{
	char **f = xx;

	if (!xx)
		return;
	while (*xx)
		free(*xx++);
	free(f);
}
