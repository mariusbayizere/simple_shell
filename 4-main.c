#include "shell.h"

int memory_environment_variable(variable *file);
char *environment_variable(variable *file, const char *burnel);
int xword_mansX(variable *file);
int retrive_environment_variable(variable *file);
int new_environment_varable(variable *file);
/**
 * environment_variable - Retrieve the value of an environment variable.
 * @file: A pointer to the variable representing the shell state.
 * @burnel: The name of the environment variable to retrieve.
 * Return:  The value of the specified environment variable on success.
 */
char *environment_variable(variable *file, const char *burnel)
{
	type *queue = file->pwd;
	char *x;

	while (queue)
	{
		x = viewing_defff(queue->data, burnel);
		if (x && *x)
			return (x);
		queue = queue->next;
	}
	return (NULL);
}
/**
 * xword_mansX - Manage X words in the shell.
 * @file: A pointer to the variable representing the shell state.
 * Return: 0 on success, -1 on failure to manage X words.
 */
int xword_mansX(variable *file)
{
	displaying_out_linkedlist(file->pwd);
	return (0);
}

/**
 * retrive_environment_variable - Retrieve an environment variable value.
 * @file: A pointer to the variable representing the shell state.
 * Return:  The value of the environment variable on success, NULL on failure.
 */
int retrive_environment_variable(variable *file)
{
	if (file->pin != 3)
	{
		print_input_string("please can you try again\n");
		return (1);
	}
	if (XXintilializedXX(file, file->n[1], file->n[2]))
		return (0);
	return (1);
}
/**
 * memory_environment_variable - Allocate memory for an environment variable.
 * @file: A pointer to the variable representing the shell state.
 * Return: 0 on success.
 */
int memory_environment_variable(variable *file)
{
	type *queue = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		putting_head_last(&queue, environ[x], 0);
	file->pwd = queue;
	return (0);
}
/**
 * new_environment_varable - Create a new environment variable in the shell.
 * @file: A pointer to the variable representing the shell state.
 * Return: 0 on success, -1 on failure to create the new environment variable.
 */
int new_environment_varable(variable *file)
{
	int x;

	if (file->pin == 1)
	{
		print_input_string("incorrect element.\n");
		return (1);
	}
	for (x = 1; x <= file->pin; x++)
		xxremove_enviromentXX(file, file->n[x]);

	return (0);
}
