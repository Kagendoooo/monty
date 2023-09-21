#include "monty.h"

/**
 * strtow - separates words in string
 * @str: string to seperate
 * @deli: delimiters to use to delimit words
 * Return: Pointers to array
 */

char **strtow(char *str, char *deli)
{
	char **words = NULL;
	int wcount, wlength, n, x = 0;

	if (str == NULL || !*str)
		return (NULL);
	wcount = get_word_count(str, deli);

	if (wcount == 0)
		return (NULL);
	words = malloc((wcount + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (x < wcount)
	{
		wlength = get_word_length(str, deli);
		if (is_deli(*str, deli))
		{
			str = get_next_word(str, deli);
		}
		words[x] = malloc((wlength + 1) * sizeof(char));
		if (words[x] == NULL)
		{
			while (x >= 0)
			{
				x--;
				free(words[x]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wlength)
		{
			words[x][n] = *(str + n);
			n++;
		}
		words[x][n] = '\0';
		str = get_next_word(str, deli);
		x++;
	}
	words[x] = NULL;
	return (words);
}

/**
 * is_deli - checks if stream has delimiter char
 * @c: character in stream
 * @deli: Pointer to delimiters
 * Return: 1 or 0
*/

int is_deli(char c, char *deli)
{
	int x = 0;

	while (deli[x])
	{
		if (deli[x] == c)
			return (1);
		x++;
	}
	return (0);
}

/**
 * get_word_length - gets the word length of word in str
 * @str: string
 * @deli: delimiters to use to delimit words
 * Return: word length of current word
*/

int get_word_length(char *str, char *deli)
{
	int wlength = 0, waiting = 1, x = 0;

	while (*(str + x))
	{
		if (is_deli(str[x], deli))
			waiting = 1;
		else if (waiting)
		{
			wlength++;
		}
		if (wlength > 0 && is_deli(str[x], deli))
			break;
		x++;
	}
	return (wlength);
}

/**
 * get_word_count - gets the word count of a string
 * @str: string
 * @deli: delimiters to use to delimit words
 * Return: the word count of the string
*/

int get_word_count(char *str, char *deli)
{
	int wcount = 0, waiting = 1, x = 0;

	while (*(str + x))
	{
		if (is_deli(str[x], deli))
			waiting = 1;
		else if (waiting)
		{
			waiting = 0;
			wcount++;
		}
		x++;
	}
	return (wcount);
}

/**
 * get_next_word - gets the next word in a string
 * @str: string
 * @deli: delimiters to use to delimit words
 * Return: pointer to first char of next word
*/

char *get_next_word(char *str, char *deli)
{
	int waiting = 0;
	int x = 0;

	while (*(str + x))
	{
		if (is_deli(str[x], deli))
			waiting = 1;
		else if (waiting)
			break;
		x++;
	}
	return (str + x);
}
