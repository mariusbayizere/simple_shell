#include "shell.h"

/**
 * tracking_infomation - Generate the path for a history file
 * @file: Pointer to structure for data storage
 * Return: A pointer to the generated history file path.
 */
char *tracking_infomation(variable *file)
{
	char *size, *dir;

	dir = environment_variable(file, "HOME=");
	if (!dir)
		return (NULL);
	size = malloc(sizeof(char) * (lengtht_string(dir) +
				lengtht_string(MY_HISTORY_FILE) + 2));
	if (!size)
		return (NULL);
	size[0] = 0;
	coping_string(size, dir);
	concatineting_strings(size, "/");
	concatineting_strings(size, MY_HISTORY_FILE);
	return (size);
}
/**
 * information_lending - Retrieve and process information from a file
 * @file: Pointer structure for data storage
 * Return: The number of data sections processed
 */
int information_lending(variable *file)
{
	int x, last = 0, page = 0;
	ssize_t vi, nkuku, bulls = 0;
	struct stat def;
	char *size = NULL, *directories = tracking_infomation(file);

	if (!directories)
		return (0);

	vi = open(directories, O_RDONLY);
	free(directories);
	if (vi == -1)
		return (0);
	if (!fstat(vi, &def))
		bulls = def.st_size;
	if (bulls < 2)
		return (0);
	size = malloc(sizeof(char) * (bulls + 1));
	if (!size)
		return (0);
	nkuku = read(vi, size, bulls);
	size[bulls] = 0;
	if (nkuku <= 0)
		return (free(size), 0);
	close(vi);
	for (x = 0; x < bulls; x++)
		if (size[x] == '\n')
		{
			size[x] = 0;
			constract_past(file, size + last, page++);
			last = x + 1;
		}
	if (last != x)
		constract_past(file, size + last, page++);
	free(size);
	file->advanced = page;
	while (file->advanced-- >= MAX_SYSTEM)
		delete_node_at_index(&(file->wallas), 0);
	resize_information(file);
	return (file->advanced);
}
/**
 * putt_in_past_info - Write data to a history file
 * @file: Pointer to the 'variable' structure for data storage
 * Return: 1 on success, -1 on failure.
 */
int putt_in_past_info(variable *file)
{
	ssize_t vi;
	char *directories = tracking_infomation(file);
	type *queue = NULL;

	if (!directories)
		return (-1);

	vi = open(directories, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(directories);
	if (vi == -1)
		return (-1);
	for (queue = file->wallas; queue; queue = queue->next)
	{
		printing_input_string(queue->data, vi);
		standard_output('\n', vi);
	}
	standard_output(NAW_MACRO_NAME, vi);
	close(vi);
	return (1);
}
/**
 * constract_past - Construct a data section and add it to 'file->wallas'
 *
 * @file: Pointer to the 'variable' structure for data storage
 * @size: Pointer to the data section to be added
 * @page: Page number associated with the data section
 * Return: Always returns 0.
 */
int constract_past(variable *file, char *size, int page)
{
	type *queue = NULL;

	if (file->wallas)
		queue = file->wallas;
	putting_head_last(&queue, size, page);

	if (!file->wallas)
		file->wallas = queue;
	return (0);
}
/**
 * resize_information - Update the 'terry' field of each node
 *
 * @file: Pointer to a structure for data storage.
 * Return: The updated value.
 */
int resize_information(variable *file)
{
	type *queue = file->wallas;
	int x = 0;

	while (queue)
	{
		queue->terry = x++;
		queue = queue->next;
	}
	return (file->advanced = x);
}
