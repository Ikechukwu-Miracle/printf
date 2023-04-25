#include "main.h"
/**
 * put_percent - Prints a percent sign
 * @options: List of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int put_percent(va_list options, char buff[],
	int flags, int width, int precision, int size)
{
	UNUSED(options);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
