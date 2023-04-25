#include "main.h"

void put_buff(char buff[], int *buff_i);

/**
 * _printf - prints formatted text to stdout
 * @format: pointer to string
 *
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	int x, pr = 0, r_val = 0;
	int flags, width, precision, size, buff_i = 0;
	va_list print;
	char buff[BSIZE];

	if (format == NULL)
		return (-1);

	va_start(print, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buff[buff_i++] = format[x];
			if (buff_i == BSIZE)
				put_buff(buff, &buff_i);
			r_val++;
		}
		else
		{
			put_buff(buff, &buff_i);
			flags = _flags(format, &x);
			width = _width(format, &x, print);
			precision = _precision(format, &x, print);
			size = _size(format, &x);
			++x;
			pr = parse_print(format, &x, print, buff,
				flags, width, precision, size);
			if (pr == -1)
				return (-1);
			r_val += pr;
		}
	}

	put_buff(buff, &buff_i);

	va_end(print);

	return (r_val);
}

/**
 * put_buff - Prints the contents of the buffer if it exist
 * @buff: Array of chars
 * @buff_i: Index at which to add next char, represents the length.
 */
void put_buff(char buff[], int *buff_i)
{
	if (*buff_i > 0)
		write(1, &buff[0], *buff_i);

	*buff_i = 0;
}
