#include "main.h"
/**
 * write_number - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @len: Number length
 * @pad: Pading char
 * @extra_ch: Extra char
 *
 * Return: Number of printed chars.
 */
int write_number(int ind, char buff[],
	int flags, int width, int precision,
	int len, char pad, char extra_ch)
{
	int x, padstart = 1;

	if (precision == 0 && ind == BSIZE - 2 && buff[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BSIZE - 2 && buff[ind] == '0')
		buff[ind] = pad = ' ';
	if (precision > 0 && precision < len)
		pad = ' ';
	while (precision > len)
		buff[--ind] = '0', len++;
	if (extra_ch != 0)
		len++;
	if (width > len)
	{
		for (x = 1; x < width - len + 1; x++)
			buff[x] = pad;
		buff[x] = '\0';
		if (flags & MINUS && pad == ' ')
		{
			if (extra_ch)
				buff[--ind] = extra_ch;
			return (write(1, &buff[ind], len) + write(1, &buff[1], x - 1));
		}
		else if (!(flags & MINUS) && pad == ' ')
		{
			if (extra_ch)
				buff[--ind] = extra_ch;
			return (write(1, &buff[1], x - 1) + write(1, &buff[ind], len));
		}
		else if (!(flags & MINUS) && pad == '0')
		{
			if (extra_ch)
				buff[--padstart] = extra_ch;
			return (write(1, &buff[padstart], x - padstart) +
				write(1, &buff[ind], len - (1 - padstart)));
		}
	}
	if (extra_ch)
		buff[--ind] = extra_ch;
	return (write(1, &buff[ind], len));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int negative, int ind,
	char buff[],
	int flags, int width, int precision, int size)
{
	int len = BSIZE - ind - 1, x = 0;
	char pad = ' ';

	UNUSED(negative);
	UNUSED(size);

	if (precision == 0 && ind == BSIZE - 2 && buff[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buff[--ind] = '0';
		len++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		pad = '0';

	if (width > len)
	{
		for (x = 0; x < width - len; x++)
			buff[x] = pad;

		buff[x] = '\0';

		if (flags & MINUS)
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], x));
		}
		else
		{
			return (write(1, &buff[0], x) + write(1, &buff[ind], len));
		}
	}

	return (write(1, &buff[ind], len));
}
