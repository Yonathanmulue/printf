#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - prints onto output
 * @format: format
 * Reurn: prited chars
 */

int _printf(const char *format, ...)
{
    int i, printed_chars = 0, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
            {
                print_buffer(buffer, &buff_ind);
            }
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            handle_print(format, &i, list, buffer);
            printed_chars += handle_print(printed);
        }
    }

    print_buffer(buffer, &buff_ind);
    va_end(list);

    return (printed_chars);
}

/*
 * print_buffer- print info in the buffer
 * @buffer: temp starage
 * @buff_ind:track the length of buffer
 */

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, &buffer[0], *buff_ind);
    }

    *buff_ind = 0;
}

