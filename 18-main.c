#include "shell.h"

/**
 * concatineting_strings - Concatenate two strings
 * @str1: The destination buffer
 * @str2: The source string
 * Return: A pointer to the destination buffer 'str1'
 */
char *concatineting_strings(char *str1, char *str2)
{
	char *mk = str1;

	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = *str2;
	return (mk);
}

/**
 * lengtht_string - Calculate the length of a string
 *
 * @xx: Pointer to the input string
 *
 * Return: The length of the input string 'xx'.
 */
int lengtht_string(char *xx)
{
	int x = 0;

	if (!xx)
		return (0);

	while (*xx++)
		x++;
	return (x);
}

/**
 * compare_two_string - Compare two strings lexicographically
 *
 * @ptr1: Pointer to the first string for comparison
 * @ptr2: Pointer to the second string for comparison
 *
 * Return: 0 if the strings are equal, a negative value if 'ptr1'
 */
int compare_two_string(char *ptr1, char *ptr2)
{
	while (*ptr1 && *ptr2)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	if (*ptr1 == *ptr2)
		return (0);
	else
		return (*ptr1 < *ptr2 ? -1 : 1);
}

/**
 * viewing_defff - Check if a string starts with a specific prefix
 * @delf: Pointer to the string to be checked
 * @humbel: Pointer to the prefix string to compare with 'delf'
 * Return: A pointer to delf.
 */
char *viewing_defff(const char *delf, const char *humbel)
{
	while (*humbel)
		if (*humbel++ != *delf++)
			return (NULL);
	return ((char *)delf);
}
