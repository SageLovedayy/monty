#include "monty.h"

/**
 *is_number - Function to check if number
 *@n: param
 *Return: 0 if number, non-zero value otherwise
 */
int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
		return (1);
	}
	return (0);
}


/**
 * isascii - Check if a character is an ASCII character
 * @c: Character to check
 * Return: 1 if ASCII, 0 otherwise
 */
int isascii(int c)
{
	return (c >= 0 && c <= 127);
}
