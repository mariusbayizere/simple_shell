#include "shell.h"

void print_input_string(char *data);
int writte_character(char vi);
int standard_output(char vi, int vim);
int printing_input_string(char *data, int vim);
/**
 * printing_input_string - Print an input string specified file descriptor.
 * @data: The input string to be printed.
 * @vim: The file the input string will be printed.
 * Return:   0 on success.
 */
int printing_input_string(char *data, int vim)
{
	int x = 0;

	if (!data)
		return (0);
	while (*data)
	{
		x += standard_output(*data++, vim);
	}
	return (x);
}
/**
 * print_input_string - Print input string the standard output.
 * @data: The input string to be printed.
 */
void print_input_string(char *data)
{
	int x = 0;

	if (!data)
		return;
	while (data[x] != '\0')
	{
		writte_character(data[x]);
		x++;
	}
}
/**
 * writte_character - Write a character to the standard output.
 * @vi: The character to be written to the standard output.
 * Return: 0 on success, -1 on failure to write the character.
 */
int writte_character(char vi)
{
	static int x;
	static char size[NEW_MACRO_NAME];

	if (vi == NAW_MACRO_NAME || x >= NEW_MACRO_NAME)
	{
		write(2, size, x);
		x = 0;
	}
	if (vi != NAW_MACRO_NAME)
		size[x++] = vi;
	return (1);
}
/**
 * standard_output - Redirect standard output.
 * @vi: The character representing the file.
 * @vim: The file descriptor to redirect.
 * Return:  None.
 */
int standard_output(char vi, int vim)
{
	static int x;
	static char size[NEW_MACRO_NAME];

	if (vi == NAW_MACRO_NAME || x >= NEW_MACRO_NAME)
	{
		write(vim, size, x);
		x = 0;
	}
	if (vi != NAW_MACRO_NAME)
		size[x++] = vi;
	return (1);
}
