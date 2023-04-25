#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
    // Retrieve a character from the variable arguments list
    char c = va_arg(types, int);

    // Call a helper function to handle writing the character to the buffer and return the number of characters printed
    return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************************* PRINT A STRING *************************/

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
    // Retrieve a string from the variable arguments list
    char *str = va_arg(types, char *);

    // If the string is NULL, replace it with "(null)" and adjust the precision
    if (str == NULL)
    {
        str = "(null)";
        if (precision >= 6)
            str = "      ";
    }

    // Get the length of the string
    int length = strlen(str);

    // Adjust the length based on the precision
    if (precision >= 0 && precision < length)
        length = precision;

    // If the width is greater than the length, add padding based on the flags
    if (width > length)
    {
        if (flags & F_MINUS)
        {
            // Left-align the string and add padding on the right
            write(1, &str[0], length);
            for (int i = width - length; i > 0; i--)
                write(1, " ", 1);
            return (width);
        }
        else
        {
            // Right-align the string and add padding on the left
            for (int i = width - length; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (width);
        }
    }

    // If the width is less than or equal to the length, just write the string
    return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
    // Print the percent sign and return the number of characters printed
    UNUSED(types);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);
    return (write(

