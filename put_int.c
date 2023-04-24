#include "main.h"
/**
  * put_int - prints integer
  * @num: number to be printed
  * Return: length of the number
  */

int put_int(int num)
{
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num / 10)
	{
		count += put_int(num / 10);
	}
	_putchar(num % 10 + '0');

	return (count);
}
