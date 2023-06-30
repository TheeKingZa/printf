#include "main.h"

/**
 * handle_integer - Handles the 'd' and 'i' conversion specifiers
 * @args: The va_list containing the arguments
 * @buffer: The buffer to store the output string
 * @count: A pointer to the count of characters printed
 *
 * Return: The number of characters printed
 */
int handle_integer(va_list args, char *buffer, int *count)
{
	int num = va_arg(args, int);

	return (print_integer(num, buffer + *count));
}

/**
 * handle_unsigned_integer - Handles the 'u' conversion specifier
 * @args: The va_list containing the arguments
 * @buffer: The buffer to store the output string
 * @count: A pointer to the count of characters printed
 *
 * Return: The number of characters printed
 */
int handle_unsigned_integer(va_list args, char *buffer, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_unsigned_integer(num, buffer + *count));
}

/* Add similar helper functions for other conversion specifiers */

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
j += handle_integer(args, buffer, count);
break;
case 'u':
j += handle_unsigned_integer(args, buffer, count);
break;
case 'o':
/* Handle 'o' conversion */
break;
case 'x':
/* Handle 'x' conversion */
break;
case 'X':
/* Handle 'X' conversion */
break;
case 'c':
/* Handle 'c' conversion */
break;
case 's':
/* Handle 's' conversion */
break;
case 'p':
/* Handle 'p' conversion */
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
