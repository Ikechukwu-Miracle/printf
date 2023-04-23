#include <unistd.h>

/**
  * _putchar - prints a character to stdout
  * @c: character to be printed
  * Return: value of character
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
