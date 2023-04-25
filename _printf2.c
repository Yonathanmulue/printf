#include "main.h"
/**
 * _printf - prints everyting passed to it
 * @format: the format of arguement
 * Return: number of chars
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else {
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					{
						char *s = va_arg(args, char *);
						while (*s)
						{
							_putchar(*s);
							count++;
							s++;
						}
						break;
					}
				case 'd':
				case 'i':
					print_int(va_arg(args, int));
					count++;
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
