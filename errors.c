#include "monty.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * usage_error - prints usage error & returns error code
 * Return: EXIT_FAILURE
 */
int usage_error(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints file open error with file name
 * @filename: name of file failed to open
 * Return: EXIT_FAILURE
 */
int f_open_error(char *filename)
{
	size_t len = 0;
	char *err_str = NULL, *err_const = "Error: Can't open file ";
	int err_const_len = 23, err_i = 0, i = 0;

	len = _strlen(filename);
	err_str = malloc(sizeof(char) * (err_const_len + len + 2));
	if (!err_str)
		return (malloc_error());
	while (err_const[i])
		err_str[err_i++] = err_const[i++];
	i = 0;
	while (filename[i])
		err_str[err_i++] = filename[i++];
	err_str[err_i++] = '\n';
	err_str[err_i++] = '\0';
	write(STDERR_FILENO, err_str, fn_len + err_const_len + 1);
	free(err_str);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error info and returns error code
 * Return: EXIT_FAILURE
 */
int malloc_error(void)
{
	write(STDERR_FILENO, "Error: malloc failed\n", 21);
	return (EXIT_FAILURE);
}
