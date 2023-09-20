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
