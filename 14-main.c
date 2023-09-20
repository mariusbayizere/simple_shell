#include "shell.h"

char *change_string_number_(long int terry, int base, int obyect);
/**
 * change_current_directory - Change the current working directory.
 * @file: A pointer to the variable representing the directory to change to.
 *
 * Return: 0 on success, -1 on failure to change the directory.
 */
int change_current_directory(variable *file)
{
	int dem;
	char *x, *big, size[1024];

	x = getcwd(size, 1024);
	if (!x)
		dusplaying_chaaracter("can not work\n");
	if (!file->n[1])
	{
		big = environment_variable(file, "HOME=");
		if (!big)
			dem = chdir((big = environment_variable(file, "PWD=")) ? big : "/");
		else
			dem = chdir(big);
	}
	else if (compare_two_string(file->n[1], "-") == 0)
	{
		if (!environment_variable(file, "OLDPWD="))
		{
			dusplaying_chaaracter(x);
			_putchar('\n');
			return (1);
		}
		dusplaying_chaaracter(environment_variable(file, "OLDPWD=")), _putchar('\n');
		dem = chdir((big = environment_variable(file, "OLDPWD=")) ? big : "/");
	}
	else
		dem = chdir(file->n[1]);
	if (dem == -1)
	{
		_displaing_Error(file, "can't cd to ");
		print_input_string(file->n[1]), writte_character('\n');
	}
	else
	{
		XXintilializedXX(file, "OLDPWD", environment_variable(file, "PWD="));
		XXintilializedXX(file, "PWD", getcwd(size, 1024));
	}
	return (0);
}

/**
 * change_string_number_ - Convert a long integer to a string  specified base.
 * @terry: The long integer to be converted.
 * @base: The base in which the conversion should be performed.
 * @obyect: The number of characters in the output string buffer.
 * Return: A pointer to the string.
 */
char *change_string_number_(long int terry, int base, int obyect)
{
	static char *xsize;
	static char sizeq[50];
	char coxin = 0;
	char *alf;
	unsigned long n = terry;

	if (!(obyect & NEW_CONSTANT) && terry < 0)
	{
		n = -terry;
		coxin = '-';

	}
	xsize = obyect & NEW_CONSTANT_NAME ? "0123456789abcdef" : "0123456789ABCDEF";
	alf = &sizeq[49];
	*alf = '\0';

	do	{
		*--alf = xsize[n % base];
		n /= base;
	} while (n != 0);

	if (coxin)
		*--alf = coxin;
	return (alf);
}
/**
 * main - execute simple shell
 * @ike: Number of command line arguments
 * @opts: Array of command line argument strings
 *
 * Return: 0 on success, 1 on error
 */
int main(int ike, char **opts)
{
	variable file[] = {MANAGER_BUFFER};
	int vi = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (vi)
			: "r" (vi));
	if (ike == 2)
	{
		vi = open(opts[1], O_RDONLY);
		if (vi == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				print_input_string(opts[0]);
				print_input_string(": 0 Can't open ");
				print_input_string(opts[1]);
				writte_character('\n');
				writte_character(NAW_MACRO_NAME);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		file->cole = vi;
	}
	memory_environment_variable(file);
	information_lending(file);
	terminal_shell(file, opts);
	return (EXIT_SUCCESS);
}

