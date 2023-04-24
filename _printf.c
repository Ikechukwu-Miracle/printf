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

	va_start(print, format);

	if (format == NULL)
		return (-1);

	for (i = 0 ; format[i] ; i++)
	{
		if (format[i] != '%')
			_putchar(format[i]);
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
		else if ((format[i + 1] == 'i') || (format[i + 1] == 'd'))
		{
			val = put_int(va_arg(print, int));
			i++;
			r_val = val - 1;
		}

		r_val += 1;
	}
	return (r_val);
}
