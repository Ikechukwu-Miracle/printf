#include "main.h"
/**
 * put_string - prints string to standard output
 * @s: pointer to string
 *
 * Return: length of string
 */

int put_string(char *s)
{
	int i, len;

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		_putchar(s[i]);
		len++;
	}

	return (len);
}
