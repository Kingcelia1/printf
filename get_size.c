#include "main.h"

/**
 * get_size - calculates size to cast the argument.
 *
 * @format: Formatted str to print the arguments.
 *
 * @i: Arguments to print.
 *
 * Return: SUCCESS
 */

int get_size(const char *format, int *i)
{
	int myInt1 = *i + 1;
	int _Size = 0;

	if (format[myInt1] == 'l')
		_Size = S_LONG;
	else if (format[myInt1] == 'h')
		_Size = S_SHORT;

	if (_Size == 0)
		*i = myInt1 - 1;
	else
		*i = myInt1;

	return (_Size);
}
