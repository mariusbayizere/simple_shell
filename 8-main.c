#include "shell.h"

void new_command_on_new_line(__attribute__((unused))int action);
int _string_conversionx(variable *file, char **alf, size_t *hight);
ssize_t xnew_line_x(variable *file);
ssize_t read_XXX_user(variable *file, char **size, size_t *sizex);
ssize_t size_xx_stored(variable *file, char *size, size_t *x);
/**
 * read_XXX_user - Read user input and store it in a string array.
 * @file: A pointer to the variable representing the shell state.
 * @size: A double pointer to a character will be stored.
 * @sizex: A pointer to a size_t variable  will be stored.
 * Return: returning q.
 */
ssize_t read_XXX_user(variable *file, char **size, size_t *sizex)
{
	size_t realy = 0;
	ssize_t q = 0;

	if (!*sizex)
	{
		free(*size);
		*size = NULL;
		signal(SIGINT, new_command_on_new_line);
#if CUSTOM_READLINE_MACRO
#else
		q = _string_conversionx(file, size, &realy);
#endif
		if (q > 0)
		{
			if ((*size)[q - 1] == '\n')
			{
				(*size)[q - 1] = '\0';
				q--;
			}
			file->costarica = 1;
			xstring_replaicing(*size);
			constract_past(file, *size, file->advanced++);
			{
				*sizex = q;
				file->xcarina = size;
			}
		}
	}
	return (q);
}
/**
 * new_command_on_new_line - Insert a new command on a new line.
 * @action: An integer parameter (unused) for compatibility.
 * Return: None.
 */
void new_command_on_new_line(__attribute__((unused))int action)
{
	dusplaying_chaaracter("\n");
	dusplaying_chaaracter("#cisfun$ ");
	_putchar(NAW_MACRO_NAME);
}
/**
 * xnew_line_x - Read and process a new line of input in the shell.
 * @file: A pointer to the variable representing the shell state.
 * Return: The number of characters read on success.
 */
ssize_t xnew_line_x(variable *file)
{
	static char *size;
	static size_t x, y, zero;
	ssize_t xi = 0;
	char **khal = &(file->xtongX), *al;

	_putchar(NAW_MACRO_NAME);
	xi = read_XXX_user(file, &size, &zero);
	if (xi == -1)
		return (-1);
	if (zero)
	{
		y = x;
		al = size + x;

		manipulation_variable(file, size, &y, x, zero);
		while (y < zero)
		{
			if (current_chacter(file, size, &y))
				break;
			y++;
		}

		x = y + 1;
		if (x >= zero)
		{
			x = zero = 0;
			file->munas = ANOTHER_MACRO_NAME;
		}

		*khal = al;
		return (lengtht_string(al));
	}

	*khal = size;
	return (xi);
}

/**
 * size_xx_stored - Store the size of a string in a variable of characters.
 * @file: A pointer to the variable representing the shell state.
 * @size: The string whose size will be determined and stored.
 * @x: A pointer to a size_t variable.
 * Return: returning the w
 */
ssize_t size_xx_stored(variable *file, char *size, size_t *x)
{
	ssize_t w = 0;

	if (*x)
		return (0);
	w = read(file->cole, size, OLD_MACRO_NAME);
	if (w >= 0)
		*x = w;
	return (w);
}
/**
 * _string_conversionx - Convert an array of strings to an array of integers.
 * @file: A pointer to the variable representing the shell state.
 * @alf: A pointer to the array of strings to be converted.
 * @hight: A pointer to an array where the converted integers will be stored.
 * Return: returning q
 */
int _string_conversionx(variable *file, char **alf, size_t *hight)
{
	static char size[OLD_MACRO_NAME];
	static size_t h, fib;
	size_t wx;
	ssize_t b = 0, q = 0;
	char *om = NULL, *wood = NULL, *xi;

	om = *alf;
	if (om && hight)
		q = *hight;
	if (h == fib)
		h = fib = 0;

	b = size_xx_stored(file, size, &fib);
	if (b == -1 || (b == 0 && fib == 0))
		return (-1);

	xi = Xfinding_single_charcterX(size + h, '\n');
	wx = xi ? 1 + (unsigned int)(xi - size) : fib;
	wood = review_size_memory(om, q, q ? q + wx : wx + 1);
	if (!wood)
		return (om ? free(om), -1 : -1);

	if (q)
		xconcatenate_stringx(wood, size + h, wx - h);
	else
		x_coping_X_string(wood, size + h, wx - h + 1);

	q += wx - h;
	h = wx;
	om = wood;

	if (hight)
		*hight = q;
	*alf = om;
	return (q);
}
