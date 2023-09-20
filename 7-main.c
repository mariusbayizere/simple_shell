#include "shell.h"

char *x_coping_X_string(char *str1, char *str2, int args);
char *xconcatenate_stringx(char *str1, char *str2, int n);
char *Xfinding_single_charcterX(char *str1, char str3);

/**
 * x_coping_X_string - Copy a substring string to another.
 * @str1: The source string from which to copy.
 * @str2: The destination copy will be placed.
 * @args: The number of characters to copy.
 * Return: A pointer to the destination string 'str2'.
 */
char *x_coping_X_string(char *str1, char *str2, int args)
{
	char *mk = str1;
	int x, y;

	x = 0;
	while (str2[x] != '\0' && x < args - 1)
	{
		str1[x] = str2[x];
		x++;
	}
	if (x < args)
	{
		y = x;
		while (y < args)
		{
			str1[y] = '\0';
			y++;
		}
	}
	return (mk);
}

/**
 * xconcatenate_stringx - Concatenate the characters of two strings.
 * @str1: The first string to be concatenated.
 * @str2: The second string to be concatenated.
 * @n: The number of characters to concatenate from each string.
 * Return: A pointer to the new concatenated string on success.
 */
char *xconcatenate_stringx(char *str1, char *str2, int n)
{
	char *mk = str1;
	int x, y;

	y = 0;
	x = 0;
	while (str1[x] != '\0')
		x++;
	while (str2[y] != '\0' && y < n)
	{
		str1[x] = str2[y];
		x++;
		y++;
	}
	if (y < n)
		str1[x] = '\0';
	return (mk);
}
/**
 * Xfinding_single_charcterX - Find the first character in string.
 * @str1: The input string in which to search.
 * @str3: The character to find within the input string.
 * Return: A pointer to the first occurrence.
 */
char *Xfinding_single_charcterX(char *str1, char str3)
{
	do {
		if (*str1 == str3)
			return (str1);
	} while (*str1++ != '\0');

	return (NULL);
}

