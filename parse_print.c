#include "main.h"
/**
 * parse_print - Prints an argument based on its type
 * @form: Formatted string in which to print the arguments.
 * @print: List of arguments to be printed.
 * @i: i.
 * @buff: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int parse_print(const char *form, int *i, va_list print, char buff[],
	int flags, int width, int precision, int size)
{
	int x, unlen = 0, r_val = -1;
	form_t form_types[] = {
		{'c', put_char}, {'s', put_string}, {'%', put_percent},
		{'i', put_int}, {'d', put_int}, {'b', put_binary},
		{'u', put_unsgnd}, {'o', put_octal}, {'x', put_hexadecimal},
		{'X', put_hexa_upper}, {'p', put_pointer}, {'S', put_non_printable},
		{'r', put_reverse}, {'R', put_rot13}, {'\0', NULL}
	};
	for (x = 0; form_types[x].form != '\0'; x++)
		if (form[*i] == form_types[x].form)
			return (form_types[x].f(print, buff, flags, width, precision, size));

	if (form_types[x].form == '\0')
	{
		if (form[*i] == '\0')
			return (-1);
		unlen += write(1, "%%", 1);
		if (form[*i - 1] == ' ')
			unlen += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (form[*i] != ' ' && form[*i] != '%')
				--(*i);
			if (form[*i] == ' ')
				--(*i);
			return (1);
		}
		unlen += write(1, &form[*i], 1);
		return (unlen);
	}
	return (r_val);
}
