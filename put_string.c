#include "main.h"

/**
 * put_char - Prints a character
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_char(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(options, int);

	return (handle_put_char(c, buff, flags, width, precision, size));
}

/**
 * put_string - Prints a string
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_string(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	int len = 0, x;
	char *s = va_arg(options, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & MINUS)
		{
			write(1, &s[0], len);
			for (x = width - len; x > 0; x--)
				_putchar(' ');
			return (width);
		}
		else
		{
			for (x = width - len; x > 0; x--)
				_putchar(' ');
			write(1, &s[0], len);
			return (width);
		}
	}

	return (write(1, s, len));
}
