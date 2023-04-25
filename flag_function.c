#include "main.h"

/**
 * _flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags
 */
int _flags(const char *format, int *i)
{
	int y, cu_i;
	int flags = 0;
	const char F_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (cu_i = *i + 1; format[cu_i] != '\0'; cu_i++)
	{
		for (y = 0; F_CH[y] != '\0'; y++)
			if (format[cu_i] == F_CH[y])
			{
				flags |= F_ARR[y];
				break;
			}

		if (F_CH[y] == 0)
			break;
	}

	*i = cu_i - 1;

	return (flags);
}
