#include "main.h"

/**
 * handler - Handles the format specifiers and builds the output string
 * @format: The format string
 * @args: The va_list containing the arguments
 * @buffer: The buffer to store the output string
 * @count: A pointer to the count of characters printed
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int handler(const char *format, va_list args, char *buffer, int *count)
{
	int i, j;
	char *str;
	unsigned int num;

	i = 0;
	j = 0;

while (format[i] != '\0')
{
	if (format[i] == '%')
	{
		i++;
	switch (format[i])
	{
		case 'd':
		case 'i':
		num = va_arg(args, int);
		j += print_integer(num, buffer + j);
			break;
		case 'u':
		num = va_arg(args, unsigned int);
		j += print_unsigned_integer(num, buffer + j);
			break;
		case 'o':
		num = va_arg(args, unsigned int);
		j += print_octal(num, buffer + j);
			break;
		case 'x':
		num = va_arg(args, unsigned int);
		j += print_hexadecimal(num, 0, buffer + j);
			break;
		case 'X':
		num = va_arg(args, unsigned int);
		j += print_hexadecimal(num, 1, buffer + j);
			break;
		case 'c':
		buffer[j++] = va_arg(args, int);
			break;
		case 's':
		str = va_arg(args, char *);
		j += print_string(str, buffer + j);
			break;
		case 'p':
		str = va_arg(args, void *);
		j += print_address(str, buffer + j);
			break;
		case '%':
		buffer[j++] = '%';
			break;
		default:
		buffer[j++] = '%';
		buffer[j++] = format[i];
			break;
		}
		}
		else
		{
			buffer[j++] = format[i];
		}
		i++;
	}
	*count = j;
	buffer[j] = '\0';
	return (j);
}

