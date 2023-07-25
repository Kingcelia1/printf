#include "main.h"

/**
 * handle_print - A function that prints an argument type based
 *
 * @fmt: Formatted string
 *
 * @list: List of args
 *
 * @ind: ind
 *
 * @buffer: Buffer Array
 *
 * @flags: Flags
 *
 * @width: width.
 *
 * @precision: Precision
 *
 * @size: Size
 *
 * Return: SUCCESS
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int myInt1, myLen = 0, myChar = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (myInt1 = 0; fmt_types[myInt1].fmt != '\0'; myInt1++)
		if (fmt[*ind] == fmt_types[myInt1].fmt)
			return (fmt_types[myInt1].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[myInt1].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		myLen += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			myLen += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		myLen += write(1, &fmt[*ind], 1);
		return (myLen);
	}
	return (myChar);
}
