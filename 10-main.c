#include "shell.h"

void Reset_information(variable *file);
void deleting_news(variable *file, int bem);
void deleting_news(variable *file, int bem);
void retriving_data(variable *file, char **opts);
/**
 * Reset_information - Initialize a variable struct.
 * @file: A pointer to a variable struct to be initialized.
 * Return: None.
 */
void Reset_information(variable *file)
{
	file->xtongX = NULL;
	file->n = NULL;
	file->dek = NULL;
	file->pin = 0;
}
/**
 * retriving_data - Retrieve and process data input options
 *
 * @file: Pointer the 'variable' structure containe data and variables
 * @opts: Array of strings representing input options
 * Return: none
 */
void retriving_data(variable *file, char **opts)
{
	int x = 0;

	file->pax = opts[0];
	if (file->xtongX)
	{
		file->n = spliting_string_delimi(file->xtongX, " \t");
		if (!file->n)
		{
			file->n = malloc(sizeof(char *) * 2);
			if (file->n)
			{
				file->n[0] = Duplicating_string(file->xtongX);
				file->n[1] = NULL;
			}
		}
		for (x = 0; file->n && file->n[x]; x++)
			;
		file->pin = x;

		exchange_token(file);
		exchange_specific_variable(file);
	}
}
/**
 * deleting_news - Perform cleanup and memory deallocation operations
 *
 * @file: Pointer to the 'variable' structure containing various data
 * @bem: Integer flag indicating additional cleanup
 * Return: none
 */
void deleting_news(variable *file, int bem)
{
	delete_allocated_memory(file->n);
	file->n = NULL;
	file->dek = NULL;
	if (bem)
	{
		if (!file->)
			free(file->xtongX);
		if (file->pwd)
			Deleting_all_element(&(file->pwd));
		if (file->wallas)
			Deleting_all_element(&(file->wallas));
		if (file->sahar)
			Deleting_all_element(&(file->sahar));
		delete_allocated_memory(file->environ);
			file->environ = NULL;
		deallocation((void **)file->xcarina);
		if (file->cole > 2)
			close(file->cole);
		_putchar(NAW_MACRO_NAME);
	}
}
