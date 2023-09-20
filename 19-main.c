#include "shell.h"

/**
 * _putchar - Write a character to the standard output
 *
 * @c: The character to be written
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int _putchar(char c)
{
	static int x;
	static char size[NEW_MACRO_NAME];

	if (c == NAW_MACRO_NAME || x >= NEW_MACRO_NAME)
	{
		write(1, size, x);
		x = 0;
	}
	if (c != NAW_MACRO_NAME)
		size[x++] = c;
	return (1);
}

/**
 * coping_string - Copy a string from one buffer to another
 *
 * @str1: The destination buffer where the string will be copied
 * @str2: The source buffer containing the string to be copied
 *
 * Return: A pointer to the destination buffer 'str1'.
 */
char *coping_string(char *str1, char *str2)
{
	int x = 0;

	if (str1 == str2 || str2 == 0)
		return (str1);
	while (str2[x])
	{
		str1[x] = str2[x];
		x++;
	}
	str1[x] = 0;
	return (str1);
}

/**
 * dusplaying_chaaracter - Display a string character by character
 *
 * @data: The string to be displayed character by character
 */
void dusplaying_chaaracter(char *data)
{
	int x = 0;

	if (!data)
		return;
	while (data[x] != '\0')
	{
		_putchar(data[x]);
		x++;
	}
}

/**
 * Duplicating_string - Duplicate a string
 *
 * @data: The string to be duplicated
 *
 * Return: A pointer to the duplicated string
 */
char *Duplicating_string(const char *data)
{
	int polf = 0;
	char *ret;

	if (data == NULL)
		return (NULL);
	while (*data++)
		polf++;
	ret = malloc(sizeof(char) * (polf + 1));
	if (!ret)
		return (NULL);
	for (polf++; polf--;)
		ret[polf] = *--data;
	return (ret);
}
