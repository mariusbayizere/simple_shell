#include "shell.h"

/**
 * searching_path - Search for and set the execution path for a command
 *
 * @file: Pointer to the structure containe command and environment data
 */
void searching_path(variable *file)
{
	int x, q;
	char *dek = NULL;

	file->dek = file->n[0];
	if (file->costarica == 1)
	{
		file->harivart++;
		file->costarica = 0;
	}
	for (x = 0, q = 0; file->xtongX[x]; x++)
		if (!finding_character(file->xtongX[x], " \t\n"))
			q++;
	if (!q)
		return;

	dek = seach_pwd(file, environment_variable(file, "PATH="), file->n[0]);
	if (dek)
	{
		file->dek = dek;
		exting_the_path(file);
	}
	else
	{
		if ((tracking_file(file) || environment_variable(file, "PATH=")
					|| file->n[0][0] == '/') && executable_command(file, file->n[0]))
			exting_the_path(file);
		else if (*(file->xtongX) != '\n')
		{
			file->status = 127;
			_displaing_Error(file, "not found\n");
		}
	}
}

/**
 * terminal_shell - Start and manage the shell's main loop
 *
 * @file: Pointer to the 'variable' structure containing shell data
 * @opts: Command-line options and arguments
 * Return: The value of kante.
 */
int terminal_shell(variable *file, char **opts)
{
	ssize_t q = 0;
	int kante = 0;

	while (q != -1 && kante != -2)
	{
		Reset_information(file);
		if (tracking_file(file))
			dusplaying_chaaracter("#cisfun$ ");
		writte_character(NAW_MACRO_NAME);
		q = xnew_line_x(file);
		if (q != -1)
		{
			retriving_data(file, opts);
			kante = putt_data(file);
			if (kante == -1)
				searching_path(file);
		}
		else if (tracking_file(file))
			_putchar('\n');
		deleting_news(file, 0);
	}
	putt_in_past_info(file);
	deleting_news(file, 1);
	if (!tracking_file(file) && file->status)
		exit(file->status);
	if (kante == -2)
	{
		if (file->done == -1)
			exit(file->status);
		exit(file->done);
	}
	return (kante);
}

/**
 * exting_the_path - Execute a command from the specified path
 *
 * @file: Pointer to the 'variable' structure
 * containing command and environment data
 * Return: none
 */
void exting_the_path(variable *file)
{
	pid_t new_process;

	new_process = fork();
	if (new_process == -1)
	{
		perror("Error:");
		return;
	}
	if (new_process == 0)
	{
		if (execve(file->dek, file->n, string_array_copy(file)) == -1)
		{
			deleting_news(file, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(file->status));
		if (WIFEXITED(file->status))
		{
			file->status = WEXITSTATUS(file->status);
			if (file->status == 126)
				_displaing_Error(file, "Permission denied\n");
		}
	}
}

/**
 * putt_data - Execute a built-in command or program based on user input
 * @file: Pointer to the structure containing command and environment data
 * Return: The result of executing the command.
 */
int putt_data(variable *file)
{
	int x, rome = -1;
	commands array[] = {
		{"exit", Exit_shell},
		{"env", xword_mansX},
		{"help", support_dir},
		{"history", _past_record},
		{"setenv", retrive_environment_variable},
		{"unsetenv", new_environment_varable},
		{"cd", change_current_directory},
		{"alias", update_Alias_character},
		{NULL, NULL}
	};

	for (x = 0; array[x].type; x++)
		if (compare_two_string(file->n[0], array[x].type) == 0)
		{
			file->harivart++;
			rome = array[x].func(file);
			break;
		}
	return (rome);
}
