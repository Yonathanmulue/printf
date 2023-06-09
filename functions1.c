#include "main.h"

/**
 * print_unsigned - This file Prints an unsigned number
 * @types: this is to show a List a of arguments
 * @buffer: In order to handle print we buffer an array
 * @flags: this is to Calculate active flags
 * @width: to get width we use this
 * @precision: Precisely specification of the function
 * @size: for the size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - this function Prints an unsigned number in octal notation
 * @types: list the type of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: this is to get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: this is to get the type of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: we use this to get width
 * @precision: Precision specification
 * @size: this is size specifier
 * Return: this function shows Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: this is to show of arguments
 * @buffer: Buffer array to handle print
 * @flags: we use this to calculates active flags
 * @width: we use this to get width
 * @precision: Precision specification
 * @size: this shows that the Size specifier
 * Return: Number of chars are printed by this
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - this function Prints a hexadecimal number in lower or upper
 * @types: we use this to Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: this is the Buffer array to handle print
 * @flags:  we use this to Calculates active flags
 * @flag_ch: this Calculates active flags
 * @width: we use this to get width
 * @precision: this is term of Precision specification
 * @size: one Size specifier
 * @size: more and second Size specification
 * Return: number of chars to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
