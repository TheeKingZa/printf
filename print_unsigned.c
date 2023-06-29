#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @args: The arguments list containing the unsigned integer
 * @buffer: The buffer to store the formatted string
 * @flags: The flags for the conversion specifier
 * @width: The field width
 * @precision: The precision
 * @size: The size of the buffer
 *
 * Return: The number of characters printed
 */
int print_unsigned(va_list args, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned int num = va_arg(args, unsigned int);
	char num_str[12]; /* Assuming unsigned int has at most 10 digits */
	int count = 0;
	char *num_ptr = num_str;

	if (flags & FLAG_ZERO)
		flags &= ~FLAG_SPACE; /* Ignore space flag if zero flag is present */

	if (precision == 0 && num == 0) /* Handle precision of 0 */
	{
		if (width > 0)
			count += handle_width(buffer, ' ', width, size);
		return (count);
	}

	/* Convert the unsigned int to a string */
	do {
		*num_ptr++ = (num % 10) + '0';
		num /= 10;
	} while (num != 0);

	*num_ptr = '\0'; /* Null-terminate the string */

	count += handle_precision(buffer, num_str, width, precision, size, flags);
	return (count);
}

