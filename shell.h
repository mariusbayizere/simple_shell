#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

#define NAW_MACRO_NAME -1
#define OLD_MACRO_NAME 1024
#define PATH 1
#define NEW_MACRO_NAME 1024
#define ANOTHER_MACRO_NAME	0
#define HISTSIZE  2
#define  MY_HISTORY_FILE ".simple_shell_history"
#define COMMAND	3
#define NEW_CONSTANT_NAME	1
#define CUSTOM_READLINE_MACRO 0
#define NEW_CONSTANT 2
#define REPLACEMENT_READLINE_MACRO 0
#define MAX_SYSTEM	4096

extern char **environ;


/**
 * struct passenger - Definition of a singly linked list node
 *
 * @terry: An integer field representing a passenger-related attribute
 * @data: A pointer to a character string containing passenger data
 * @next: A pointer to the next node in the singly linked list
 */
typedef struct passenger
{
	int terry;
	char *data;
	struct passenger *next;
} type;

/**
 * struct iptables_starage - Definition of a complex data storage structure
 *
 * @xtongX: A pointer to a character string storing a specific data field
 * @dek: A pointer to a character string storing another data field
 * @n: A pointer to an array of character pointers for data storage
 * @harivart: An unsigned integer field representing a data attribute
 * @pin: An integer field representing a data attribute
 * @costarica: An integer field representing a data attribute
 * @pwd: A pointer to a linked list structure for data storage
 * @done: An integer field representing a data attribute
 * @advanced: An integer field representing a data attribute
 * @pax: A pointer to a character string storing a data attribute
 * @environ: A pointer to an array of character pointers for data storage
 * @wallas: A pointer to a linked list structure for data storage
 * @status: An integer field representing a data attribute
 * @sahar: A pointer to a linked list structure for data storage
 * @maxx: An integer field representing a data attribute
 * @cole: An integer field representing a data attribute
 * @xcarina: A pointer to an array of character pointers for data storage
 * @munas: An integer field representing a data attribute
 */
typedef struct iptables_starage
{
	char *xtongX;
	char **n;
	char *dek;
	int pin;
	unsigned int harivart;
	int done;
	int costarica;
	char *pax;
	type *pwd;
	type *wallas;
	type *sahar;
	char **environ;
	int maxx;
	int status;

	char **xcarina;
	int munas;
	int cole;
	int advanced;
} variable;

#define MANAGER_BUFFER \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct lazio - Definition of a structure for storing command data
 *
 * @type: A pointer to a character string representing the command type
 * @func: A function pointer to the correspond command function
 */
typedef struct lazio
{
	char *type;
	int (*func)(variable *);
} commands;

int executable_command(variable *, char *);
void exting_the_path(variable *);
int terminal_shell(variable *, char **);
void searching_path(variable *);
type *wood_tails(type **, const char *, int);
int resize_information(variable *file);
int information_lending(variable *file);
int putt_data(variable *);
char *character_Duplication(char *, int, int);
char *seach_pwd(variable *, char *, char *);
void print_input_string(char *);
int writte_character(char);
int standard_output(char vi, int vim);
int printing_input_string(char *data, int fd);
int lengtht_string(char *);
int compare_two_string(char *, char *);
char *concatineting_strings(char *, char *);
char *viewing_defff(const char *, const char *);
char *coping_string(char *, char *);
int _putchar(char);
void dusplaying_chaaracter(char *);
char *Duplicating_string(const char *);
char *x_coping_X_string(char *, char *, int);
char *Xfinding_single_charcterX(char *, char);
char *xconcatenate_stringx(char *, char *, int);
void delete_allocated_memory(char **);
char **xspriliting_string_part(char *, char);
void *review_size_memory(void *, unsigned int, unsigned int);
char **spliting_string_delimi(char *, char *);
char *block_memory(char *, char, unsigned int);
int deallocation(void **);
int alphabetic(int);
int tracking_file(variable *);
int xstring_Enter_x(char *);
int finding_character(char, char *);
int string_integer(char *);
int xfunction_pinter(int, int);
void _displaing_Error(variable *, char *);
void xstring_replaicing(char *);
char *change_string_number_(long int, int, int);
int Exit_shell(variable *);
int change_current_directory(variable *);
int support_dir(variable *);
int _past_record(variable *);
void new_command_on_new_line(int);
int update_Alias_character(variable *);
ssize_t xnew_line_x(variable *);
int _string_conversionx(variable *, char **, size_t *);
void deleting_news(variable *, int);
void Reset_information(variable *);
void retriving_data(variable *, char **);
char *environment_variable(variable *, const char *);
int memory_environment_variable(variable *);
int xword_mansX(variable *);
int retrive_environment_variable(variable *);
int new_environment_varable(variable *);
int XXintilializedXX(variable *, char *, char *);
char **string_array_copy(variable *);
int putt_in_past_info(variable *file);
int xxremove_enviromentXX(variable *, char *);
char *tracking_infomation(variable *file);
int constract_past(variable *file, char *size, int page);
size_t displaying_out_linkedlist(const type *);
type *putting_head_last(type **, const char *, int);
void Deleting_all_element(type **);
int delete_node_at_index(type **, unsigned int);
char **xString_information(type *);
size_t measure_linked_list(const type *);
ssize_t searching_element(type *, type *);
size_t displaing_out_element(const type *);
void manipulation_variable(variable *, char *, size_t *, size_t, size_t);
type *linked_list_nodesx(type *, char *, char);
int exchange_specific_variable(variable *);
int current_chacter(variable *, char *, size_t *);
int exchnge_character(char **, char *);
int exchange_token(variable *);

#endif
