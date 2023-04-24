#include "main.h"
/**
 * _printf - prints formatted text to stdout
 * @format: pointer to string
 *
 * Return: number of printed characters
 */

int _printf(const char *format, ...)
{
	int i, val, r_val = 0;
	va_list print;

	if (format == NULL)
		return (-1);
	else
	{
		va_start(print, format);

		for (i = 0 ; format[i] ; i++)
		{
			if (format[i] != '%')
			{
				_putchar(format[i]);
			}
			else if (format[i + 1] == 'c')
			{
				_putchar(va_arg(print, int));
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
			}
			else if (format[i + 1] == 's')
			{
				val = put_string(va_arg(print, char *));
				i++;
				r_val = val - 1;
			}
			r_val += 1;
		}
	}
	return (r_val);
}
