#include "main.h"

/**
 * handle_put_char - Prints a string
 * @c: char types.
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_put_char(char c, char buff[],
	int flags, int width, int precision, int size)
{
	int x = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO)
		pad = '0';

	buff[x++] = c;
	buff[x] = '\0';

	if (width > 1)
	{
		buff[BSIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buff[BSIZE - x - 2] = pad;

		if (flags & MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BSIZE - x - 1], width - 1));
		else
			return (write(1, &buff[BSIZE - x - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/**
 * put_number - Prints a string
 * @negative: Lista of arguments
 * @ind: char types.
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int put_number(int negative, int ind, char buff[],
	int flags, int width, int precision, int size)
{
	int len = BSIZE - ind - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & MINUS))
		pad = '0';
	if (negative)
		extra_ch = '-';
	else if (flags & PLUS)
		extra_ch = '+';
	else if (flags & SPACE)
		extra_ch = ' ';

	return (write_number(ind, buff, flags, width, precision,
				len, pad, extra_ch));
}
