#include "main.h"

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (write(1, &c, 1));
}

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	if (str == NULL)
		str = "(null)";
	return (write(1, str, strlen(str)));
}

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%", 1));
}

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = va_arg(types, int);
	char num_str[20];
	sprintf(num_str, "%d", n);
	return (write(1, num_str, strlen(num_str)));
}

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n = va_arg(types, unsigned int);
	char bin_str[33];
	itoa(n, bin_str, 2);
	return (write(1, bin_str, strlen(bin_str)));
}

