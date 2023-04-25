#include "main.h"

/**
 * put_pointer - Prints the value of a pointer variable
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int put_pointer(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	char extra_ch = 0, pad = ' ';
	int ind = BSIZE - 2, len = 2, padstart = 1;
	unsigned long numaddrs;
	char map[] = "0123456789abcdef";
	void *addrs = va_arg(options, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BSIZE - 1] = '\0';
	UNUSED(precision);

	numaddrs = (unsigned long)addrs;

	while (numaddrs > 0)
	{
		buff[ind--] = map[numaddrs % 16];
		numaddrs /= 16;
		len++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		pad = '0';
	if (flags & PLUS)
		extra_ch = '+', len++;
	else if (flags & SPACE)
		extra_ch = ' ', len++;

	ind++;

	return (write_pointer(buff, ind, len,
		width, flags, pad, extra_ch, padstart));
}

/**
 * put_non_printable - Prints ascii codes in hexa of non printable chars
 * @options: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_non_printable(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	int x = 0, offset = 0;
	char *s = va_arg(options, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[x] != '\0')
	{
		if (printable(s[x]))
			buff[x + offset] = s[x];
		else
			offset += append_hexa(s[x], buff, x + offset);

		x++;
	}

	buff[x + offset] = '\0';

	return (write(1, buff, x + offset));
}
