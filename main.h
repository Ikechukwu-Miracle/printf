#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BSIZE 1024

#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16

#define SHORT_SIZE 1
#define LONG_SIZE 2

/**
 * struct form - Struct op
 *
 * @form: The format.
 * @f: The function associated.
 */
struct form
{
	char form;
	int (*f)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct form form_t - Struct op
 *
 * @form: The format.
 * @form_t: The function associated.
 */
typedef struct form form_t;

int _putchar(char c);
int _printf(const char *format, ...);
int parse_print(const char *form, int *i,
va_list print, char buff[], int flags, int width, int precision, int size);

int put_char(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_string(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_percent(va_list options, char buff[],
	int flags, int width, int precision, int size);

int put_int(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_binary(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_unsgnd(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_octal(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_hexadecimal(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_hexa_upper(va_list options, char buff[],
	int flags, int width, int precision, int size);
int put_hexa(va_list options, char map[], char buff[], int flags,
	char flagch, int width, int precision, int size);

int put_non_printable(va_list options, char buff[],
	int flags, int width, int precision, int size);

int put_pointer(va_list options, char buff[],
	int flags, int width, int precision, int size);

int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list print);
int _precision(const char *format, int *i, va_list print);
int _size(const char *format, int *i);

int put_reverse(va_list options, char buff[],
	int flags, int width, int precision, int size);

int put_rot13(va_list options, char buff[],
	int flags, int width, int precision, int size);

int handle_put_char(char c, char buff[],
	int flags, int width, int precision, int size);
int put_number(int negative, int ind, char buff[],
	int flags, int width, int precision, int size);
int write_number(int ind, char bffr[], int flags, int width, int precision,
	int length, char pad, char extra_ch);
int write_pointer(char buff[], int ind, int len,
	int width, int flags, char pad, char extra_ch, int padstart);

int write_unsgnd(int negative, int ind, char buff[],
	int flags, int width, int precision, int size);

int printable(char);
int append_hexa(char, char[], int);
int _isdigit(char);

long int con_size_num(long int num, int size);
long int con_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
