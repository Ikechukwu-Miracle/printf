#include "main.h"
/**
 * write_pointer - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @len: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @pad: Char representing the padding
 * @extra_ch: Char representing extra char
 * @padstart: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buff[], int ind, int len,
	int width, int flags, char pad, char extra_ch, int padstart)
{
	int x;

	if (width > len)
	{
		for (x = 3; x < width - len + 3; x++)
			buff[x] = pad;
		buff[x] = '\0';
		if (flags & MINUS && pad == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_ch)
				buff[--ind] = extra_ch;
			return (write(1, &buff[ind], len) + write(1, &buff[3], x - 3));
		}
		else if (!(flags & MINUS) && pad == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_ch)
				buff[--ind] = extra_ch;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
		}
		else if (!(flags & MINUS) && pad == '0')
		{
			if (extra_ch)
				buff[--padstart] = extra_ch;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padstart], x - padstart) +
				write(1, &buff[ind], len - (1 - padstart) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_ch)
		buff[--ind] = extra_ch;
	return (write(1, &buff[ind], BSIZE - ind - 1));
}
