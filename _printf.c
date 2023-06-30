#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *buffer;
	int count = 0;

	va_start(args, format);
	buffer = malloc(1024 * sizeof(char));

	if (buffer == NULL)
	{
		va_end(args);
		return (-1);
	}

	count = handler(format, args, buffer, &count);
	write(1, buffer, count);

	free(buffer);
	va_end(args);

	return (count);
}


