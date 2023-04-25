#include "main.h"

/**
 * _size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int _size(const char *format, int *i)
{
	int cu_i = *i + 1;
	int size = 0;

	if (format[cu_i] == 'l')
		size = LONG_SIZE;
	else if (format[cu_i] == 'h')
		size = SHORT_SIZE;

	if (size == 0)
		*i = cu_i - 1;
	else
		*i = cu_i;

	return (size);
}
