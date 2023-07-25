#include "main.h"

/**
 * is_printable - A function that evaluates if a character can be printed.
 *
 * @c: Char to check.
 *
 * Return: SUCCESS
 *
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - A function that appends ascci in hex code to buffer
 *
 * @buffer: An array of characters
 *
 * @i: Index to start appending.
 *
 * @ascii_code: ASSCI STYLE
 *
 * Return: SUCCESS
 *
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char myMapChar[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = myMapChar[ascii_code / 16];
	buffer[i] = myMapChar[ascii_code % 16];

	return (3);
}

/**
 * is_digit - A function that checks if a character is an integer
 *
 * @c: Character to check
 *
 * Return: SUCCESS
 *
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - A function that casts a number to specified size
 *
 * @num: Int to cast
 *
 * @size: Type int
 *
 * Return: SUCCESS
 *
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - A function that casts an int to the specified size
 *
 * @num: Int to cast
 *
 * @size: Type int
 *
 * Return: SUCCESS
 *
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
