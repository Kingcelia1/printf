#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - A function that Prints a string
 *
 * @c: Character types.
 *
 * @buffer: Buffer
 *
 * @flags: Flags
 *
 * @width: Width
 *
 * @precision: Specifies the precision
 *
 * @size: Specifies the size
 *
 * Return: SUCCESS
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int myInt1 = 0;
	char _myPadd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		_myPadd = '0';

	buffer[myInt1++] = c;
	buffer[myInt1] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (myInt1 = 0; myInt1 < width - 1; myInt1++)
			buffer[BUFF_SIZE - myInt1 - 2] = _myPadd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - myInt1 - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - myInt1 - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - A function that prints a string
 *
 * @is_negative: Arg list
 *
 * @ind: character type
 *
 * @buffer: Buffer
 *
 * @flags: Flags
 *
 * @width: Calculates the width
 *
 * @precision: precision
 *
 * @size: Size
 *
 * Return: SUCCESS
 */

int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int myLength = BUFF_SIZE - ind - 1;
	char _myPadd = ' ', myExtraChar = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		_myPadd = '0';
	if (is_negative)
		myExtraChar = '-';
	else if (flags & F_PLUS)
		myExtraChar = '+';
	else if (flags & F_SPACE)
		myExtraChar = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		myLength, _myPadd, myExtraChar));
}

/**
 * write_num - A function that Writes a number using a buffer
 *
 * @id: Buffer start index
 *
 * @bf: Buffer
 *
 * @flags: Flags
 *
 * @width: calculates the width
 *
 * @prec: Specifies the precision
 *
 * @ln: length
 *
 * @padd: pading
 *
 * @extra_c: character
 *
 * Return: SUCCESS
 *
 */

int write_num(int id, char bf[],
	int flags, int width, int prec,
	int ln, char padd, char extra_c)
{
	int myInt1;
	int mySpad = 1;

	if (prec == 0 && id == BUFF_SIZE - 2 && bf[id] == '0' && width == 0)
		return (0);
	if (prec == 0 && id == BUFF_SIZE - 2 && bf[id] == '0')
		bf[id] = padd = ' ';
	if (prec > 0 && prec < ln)
		padd = ' ';
	while (prec > ln)
		bf[--id] = '0', ln++;
	if (extra_c != 0)
		ln++;
	if (width > ln)
	{
		for (myInt1 = 1; myInt1 < width - ln + 1; myInt1++)
			bf[myInt1] = padd;
		bf[myInt1] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				bf[--id] = extra_c;
			return (write(1, &bf[id], ln) + write(1, &bf[1], myInt1 - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				bf[--id] = extra_c;
			return (write(1, &bf[1], myInt1 - 1) + write(1, &bf[id], ln));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				bf[--mySpad] = extra_c;
			return (write(1, &bf[mySpad], myInt1 - mySpad) +
				write(1, &bf[id], ln - (1 - mySpad)));
		}
	}
	if (extra_c)
		bf[--id] = extra_c;
	return (write(1, &bf[id], ln));

}

/**
 * write_unsgnd - A fuction that writes unsigned integer
 *
 * @is_negative: int
 *
 * @ind: Buffer start index
 *
 * @buffer: Array of characters
 *
 * @flags: Flags
 *
 * @width: Width
 *
 * @precision: Precision
 *
 * @size: Size
 *
 * Return: SUCCESS
 */

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int myLength = BUFF_SIZE - ind - 1, myInt1 = 0;
	char myPad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < myLength)
		myPad = ' ';

	while (precision > myLength)
	{
		buffer[--ind] = '0';
		myLength++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		myPad = '0';

	if (width > myLength)
	{
		for (myInt1 = 0; myInt1 < width - myLength; myInt1++)
			buffer[myInt1] = myPad;

		buffer[myInt1] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], myLength) + write(1, &buffer[0], myInt1));
		}
		else
		{
			return (write(1, &buffer[0], myInt1) + write(1, &buffer[ind], myLength));
		}
	}

	return (write(1, &buffer[ind], myLength));
}

/**
 * write_pointer - A function that outputs a memory address
 *
 * @buffer: Buffer
 *
 * @ind: Buffer start index
 *
 * @length: Length
 *
 * @width: Width
 *
 * @flags: Flags
 *
 * @padd: padding
 *
 * @extra_c: axtra char
 *
 * @padd_start: Padding start index
 *
 * Return: SUCCESS
 */

int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int myInt1;

	if (width > length)
	{
		for (myInt1 = 3; myInt1 < width - length + 3; myInt1++)
			buffer[myInt1] = padd;
		buffer[myInt1] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], myInt1 - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], myInt1 - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], myInt1 - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
