#include "shell.h"

/**
 * spliting_string_delimi - Split a string into tokens based on delimiters
 *
 * @data: The string to be split
 * @xx:   The delimiter characters for splitting
 *
 * Return: An array of strings (tokens) created by splitting'
 */

char **spliting_string_delimi(char *data, char *xx)
{
	char **ptr;
	int x, y, q, of, counter = 0;

	if (data == NULL || data[0] == 0)
		return (NULL);
	if (!xx)
		xx = " ";
	for (x = 0; data[x] != '\0'; x++)
		if (!finding_character(data[x], xx) && (finding_character(data[x + 1], xx) ||
					!data[x + 1]))
			counter++;

	if (counter == 0)
		return (NULL);
	ptr = malloc((1 + counter) * sizeof(char *));
	if (!ptr)
		return (NULL);
	for (x = 0, y = 0; y < counter; y++)
	{
		while (finding_character(data[x], xx))
			x++;
		q = 0;
		while (!finding_character(data[x + q], xx) && data[x + q])
			q++;
		ptr[y] = malloc((q + 1) * sizeof(char));
		if (!ptr[y])
		{
			for (q = 0; q < y; q++)
				free(ptr[q]);
			free(ptr);
			return (NULL);
		}
		for (of = 0; of < q; of++)
			ptr[y][of] = data[x++];
		ptr[y][of] = 0;
	}
	ptr[y] = NULL;
	return (ptr);
}



/**
 * xspriliting_string_part - Split a string into tokens a delimiter character
 *
 * @data: The string to be split
 * @xx:   The delimiter character for splitting
 *
 * Return: An array of strings.
 */
char **xspriliting_string_part(char *data, char xx)
{
	int x, y, q, of, counter = 0;
	char **temp;

	if (data == NULL || data[0] == 0)
		return (NULL);
	for (x = 0; data[x] != '\0'; x++)
		if ((data[x] != xx && data[x + 1] == xx) ||
				    (data[x] != xx && !data[x + 1]) || data[x + 1] == xx)
			counter++;
	if (counter == 0)
		return (NULL);
	temp = malloc((1 + counter) * sizeof(char *));
	if (!temp)
		return (NULL);
	for (x = 0, y = 0; y < counter; y++)
	{
		while (data[x] == xx && data[x] != xx)
			x++;
		q = 0;
		while (data[x + q] != xx && data[x + q] && data[x + q] != xx)
			q++;
		temp[y] = malloc((q + 1) * sizeof(char));
		if (!temp[y])
		{
			for (q = 0; q < y; q++)
				free(temp[q]);
			free(temp);
			return (NULL);
		}
		for (of = 0; of < q; of++)
			temp[y][of] = data[x++];
		temp[y][of] = 0;
	}
	temp[y] = NULL;
	return (temp);
}
