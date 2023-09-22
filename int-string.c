#include <stdlib.h>

/**
 *  get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 * Return: character pointer to newly created string. NULL if malloc fails.
*/
char *get_int(int num)
{
	unsigned int temp;
	int len = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	len = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, len);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @i: integer to get absolute value of
 * Return: unsigned integer abs rep of i
*/
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 *  get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number rep
 * Return: integer containing length of buffer
*/
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 * Return: always void.
*/
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem, x = buff_size - 1;

	buff[buff_size] = '\0';
	while (x >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[x] = rem + 87;
		else
			buff[x] = rem + '0';
		num /= base;
		x--;
	}
}
