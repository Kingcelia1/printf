#include "main.h"

/**
 * get_width - Calculates width
 *
 * @format: Formatted str to print Arguments.
 *
 * @i: List of Arguments to print.
 *
 * @list: list of Arguments.
 *
 * Return: SUCCESS
 *
 */

int get_width(const char *format, int *i, va_list list)
{
	int myInt1;
	int _Wdth = 0;

	for (myInt1 = *i + 1; format[myInt1] != '\0'; myInt1++)
	{
		if (is_digit(format[myInt1]))
		{
			_Wdth *= 10;
			_Wdth += format[myInt1] - '0';
		}
		else if (format[myInt1] == '*')
		{
			myInt1++;
			_Wdth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = myInt1 - 1;

	return (_Wdth);
}
