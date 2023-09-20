#include "shell.h"


/**
 * character_Duplication - Duplicate a portion of a character array
 * @modirc: Pointer to the character array to be duplicated
 * @ones: Starting index of the portion to be duplicated
 * @last: Ending index of the portion to be duplicated
 * Return: A pointer to the duplicated.
 */
char *character_Duplication(char *modirc, int ones, int last)
{
	static char size[1024];
	int x = 0, t = 0;

	for (t = 0, x = ones; x < last; x++)
		if (modirc[x] != ':')
			size[t++] = modirc[x];
	size[t] = 0;
	return (size);
}
/**
 * seach_pwd - Search for executable file in directories
 * @file: Pointer to the structure for data storage
 * @modirc: String containing a colon-separated list of directories
 * @ls: Name of the executable file to search for
 * Return: A pointer to the path of file found.
 */
char *seach_pwd(variable *file, char *modirc, char *ls)
{
	int x = 0, negative = 0;
	char *dek;

	if (!modirc)
		return (NULL);
	if ((lengtht_string(ls) > 2) && viewing_defff(ls, "./"))
	{
		if (executable_command(file, ls))
			return (ls);
	}
	while (1)
	{
		if (!modirc[x] || modirc[x] == ':')
		{
			dek = character_Duplication(modirc, negative, x);
			if (!*dek)
				concatineting_strings(dek, ls);
			else
			{
				concatineting_strings(dek, "/");
				concatineting_strings(dek, ls);
			}
			if (executable_command(file, dek))
				return (dek);
			if (!modirc[x])
				break;
			negative = x;
		}
		x++;
	}
	return (NULL);
}
/**
 * executable_command - Check if a file is executable
 * @file: Pointer to the structure (not used in this function)
 * @dek: Path to the file to be checked
 * Return: 1 if the file is executable.
 */
int executable_command(variable *file, char *dek)
{
	struct stat def;

	(void)file;
	if (!dek || stat(dek, &def))
		return (0);

	if (def.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
