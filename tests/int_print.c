#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_int - prints integer
 * @n: the integer to be printed
 *
 * Retun: nothing
 */
void print_int(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_int(n / 10);
	_putchar(n % 10 + '0');
}
