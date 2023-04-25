#include "main.h"

/**
 * put_unsgnd - Prints an unsigned number
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int put_unsgnd(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	int x = BSIZE - 2;
	unsigned long int number = va_arg(options, unsigned long int);

	number = con_size_unsgnd(number, size);

	if (number == 0)
		buff[x--] = '0';

	buff[BSIZE - 1] = '\0';

	while (number > 0)
	{
		buff[x--] = (number % 10) + '0';
		number /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buff, flags, width, precision, size));
}

/**
 * put_octal - Prints an unsigned number in octal notation
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_octal(va_list options, char buff[],
	int flags, int width, int precision, int size)
{

	int x = BSIZE - 2;
	unsigned long int num = va_arg(options, unsigned long int);
	unsigned long int init = num;

	UNUSED(width);

	num = con_size_unsgnd(num, size);

	if (num == 0)
		buff[x--] = '0';

	buff[BSIZE - 1] = '\0';

	while (num > 0)
	{
		buff[x--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASH && init != 0)
		buff[x--] = '0';

	x++;

	return (write_unsgnd(0, x, buff, flags, width, precision, size));
}

/**
 * put_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @options: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_hexadecimal(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	return (put_hexa(options, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}

/**
 * put_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @options: Lista of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_hexa_upper(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	return (put_hexa(options, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}

/**
 * put_hexa - Prints a hexadecimal number in lower or upper
 * @options: Lista of arguments
 * @map: Array of values to map the number to
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flagch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_hexa(va_list options, char map[], char buff[],
	int flags, char flagch, int width, int precision, int size)
{
	int x = BSIZE - 2;
	unsigned long int number = va_arg(options, unsigned long int);
	unsigned long int init = number;

	UNUSED(width);

	number = con_size_unsgnd(number, size);

	if (number == 0)
		buff[x--] = '0';

	buff[BSIZE - 1] = '\0';

	while (number > 0)
	{
		buff[x--] = map[number % 16];
		number /= 16;
	}

	if (flags & HASH && init != 0)
	{
		buff[x--] = flagch;
		buff[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buff, flags, width, precision, size));
}
