#include "main.h"

/**
 * _width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @print: list of arguments.
 *
 * Return: width.
 */
int _width(const char *format, int *i, va_list print)
{
	int cu_i;
	int width = 0;

	for (cu_i = *i + 1; format[cu_i] != '\0'; cu_i++)
	{
		if (_isdigit(format[cu_i]))
		{
			width *= 10;
			width += format[cu_i] - '0';
		}
		else if (format[cu_i] == '*')
		{
			cu_i++;
			width = va_arg(print, int);
			break;
		}
		else
			break;
	}

	*i = cu_i - 1;

	return (width);
}
