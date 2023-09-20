#include "shell.h"

void _displaing_Error(variable *file, char *zuba);
int string_integer(char *vi);
void xstring_replaicing(char *size);

/**
 * _displaing_Error - Display an error message.
 * @file: A pointer to the variable representing the shell state.
 * @zuba: The error message to be displayed.
 * Return:  None.
 */
void _displaing_Error(variable *file, char *zuba)
{
	print_input_string(file->pax);
	print_input_string(": ");
	xfunction_pinter(file->harivart, STDERR_FILENO);
	print_input_string(": ");
	print_input_string(file->n[0]);
	print_input_string(": ");
	print_input_string(zuba);
}
/**
 * string_integer - Convert a string to an integer.
 * @vi: The input string to be converted.
 * Return:  string on success, or 0 on failure.
 */
int string_integer(char *vi)
{
	int x = 0;
	unsigned long int xsun = 0;

	if (*vi == '+')
		vi++;
	for (x = 0;  vi[x] != '\0'; x++)
	{
		if (vi[x] >= '0' && vi[x] <= '9')
		{
			xsun *= 10;
			xsun += (vi[x] - '0');
			if (xsun > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (xsun);
}
/**
 * xstring_replaicing - Replace characters in a string.
 * @size: The string in which characters will be replaced.
 * Return: None.
 */
void xstring_replaicing(char *size)
{
	int x;

	for (x = 0; size[x] != '\0'; x++)
		if (size[x] == '#' && (!x || size[x - 1] == ' '))
		{
			size[x] = '\0';
			break;
		}
}
