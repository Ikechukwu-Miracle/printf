#include "main.h"

/**
 * printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa - Append ascci in hexadecimal code to buffer
 * @buff: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_value: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa(char ascii_value, char buff[], int i)
{
	char map[] = "0123456789ABCDEF";
	if (ascii_value < 0)
		ascii_value *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = map[ascii_value / 16];
	buff[i] = map[ascii_value % 16];

	return (3);
}

/**
 * _isdigit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * con_size_num - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int con_size_num(long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((short)num);

	return ((int)num);
}

/**
 * con_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int con_size_unsgnd(unsigned long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
