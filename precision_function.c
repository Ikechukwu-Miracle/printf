#include "main.h"

/**
 * _precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @print: list of arguments.
 *
 * Return: Precision.
 */
int _precision(const char *format, int *i, va_list print)
{
	int cu_i = *i + 1;
	int precision = -1;

	if (format[cu_i] != '.')
		return (precision);

	precision = 0;

	for (cu_i += 1; format[cu_i] != '\0'; cu_i++)
	{
		if (_isdigit(format[cu_i]))
		{
			precision *= 10;
			precision += format[cu_i] - '0';
		}
		else if (format[cu_i] == '*')
		{
			cu_i++;
			precision = va_arg(print, int);
			break;
		}
		else
			break;
	}

	*i = cu_i - 1;

	return (precision);
}
