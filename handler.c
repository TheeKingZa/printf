#include "main.h"

/**
 * handler - Handles the conversion specifiers
 * @format: The format string
 * @args: The va_list containing the arguments
 * @buffer: The buffer to store the formatted string
 * @count: The count of characters printed
 *
 * Return: The count of characters printed
 */
int handler(const char *format, va_list args, char *buffer, int *count)
{
	int i = 0, j = 0;
	char *str;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					buffer[j++] = va_arg(args, int);
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
					{
						buffer[j++] = *str++;
					}
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
		(*count)++;
	}

	buffer[j] = '\0';

	return (*count);
}

