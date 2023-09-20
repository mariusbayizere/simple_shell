#include "shell.h"

int Exit_shell(variable *file);
int support_dir(variable *file);

/**
 * support_dir - Support a directory operation within the shell.
 * @file: A pointer to the variable representing the shell state.
 * Return: 0 on success, -1 on failure to support the directory operation.
 */
int support_dir(variable *file)
{
	char **mumo;

	mumo = file->n;
	dusplaying_chaaracter("is not allowed \n");
	if (0)
		dusplaying_chaaracter(*mumo);
	return (0);
}
/**
 * Exit_shell - Exit the shell program and perform cleanup.
 * @file: A pointer to the variable representing the shell state.
 * Return: This function does not return a value.
 */
int Exit_shell(variable *file)
{
	int yves;

	if (file->n[1])
	{
		yves = string_integer(file->n[1]);
		if (yves == -1)
		{
			file->status = 2;
			_displaing_Error(file, "your information are not allowed: ");
			print_input_string(file->n[1]);
			writte_character('\n');
			return (1);
		}
		file->done = string_integer(file->n[1]);
		return (-2);
	}
	file->done = -1;
	return (-2);
}
