#include "shell.h"

int finding_character(char x, char *psr);
int tracking_file(variable *file);
int xstring_Enter_x(char *x);
int alphabetic(int x);
int xfunction_pinter(int yamal, int vi);

/**
 * finding_character - Checking the character is delimiter in string.
 * @x: The character to checking for as a delimiter.
 * @psr: A pointer to the string to search within.
 * Return: 1 if 'x' is a delimiter in 'psr', 0 otherwise.
 */
int finding_character(char x, char *psr)
{
	while (*psr)
		if (*psr++ == x)
			return (1);
	return (0);
}

/**
 * tracking_file - Track information about a variable's associated file.
 * @file: A pointer to the variable the file to be tracked.
 * @file: A pointer to the variable the file to track.
 *
 * Return: This function does not return a value.
 */
int tracking_file(variable *file)
{
	return (isatty(STDIN_FILENO) && file->cole <= 2);
}

/**
 * xstring_Enter_x - verify if character is string digit.
 * @x: A pointer to the input string to check.
 * Return: 1 if the character 'x' is found in the string, 0 otherwise.
 */
int xstring_Enter_x(char *x)
{
	int q, operat = 1, bord = 0, ubuntu;
	unsigned int xsun = 0;

	for (q = 0; x[q] != '\0' && bord != 2; q++)
	{
		if (x[q] == '-')
			operat *= -1;

		if (x[q] >= '0' && x[q] <= '9')
		{
			bord = 1;
			xsun *= 10;
			xsun += (x[q] - '0');
		}
		else if (bord == 1)
			bord = 2;
	}

	if (operat == -1)
		ubuntu = -xsun;
	else
		ubuntu = xsun;

	return (ubuntu);
}

/**
 * alphabetic - Check if a character is an alphabetic character.
 * @x: The character to be checked.
 * Return: 1 if 'x' is an alphabetic character, 0 otherwise.
 */
int alphabetic(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * xfunction_pinter - Perform a custom operation based on two integer values.
 * @yamal: The first integer input for the operation.
 * @vi: The second integer input for the operation.
 * Return:  The result of the custom operation.
 */
int xfunction_pinter(int yamal, int vi)
{
	int (*__putchar)(char) = _putchar;
	int x, number = 0;
	unsigned int om, pyh;

	if (vi == STDERR_FILENO)
		__putchar = writte_character;
	if (yamal < 0)
	{
		om = -yamal;
		__putchar('-');
		number++;
	}
	else
		om = yamal;
	pyh = om;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (om / x)
		{
			__putchar('0' + pyh / x);
			number++;
		}
		pyh %= x;
	}
	__putchar('0' + pyh);
	number++;

	return (number);
}
