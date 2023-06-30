
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char buffer[BUFFER_SIZE];
char *buffer_ptr = buffer;

va_start(args, format);

while (*format)
{
	if (*format == '%')
	{
	format++;
/* Handle conversion specifier */
	count += handler(format, args, buffer_ptr, &count);
	}
	else
	{
/* Regular character, copy to buffer */
	*buffer_ptr = *format;
	buffer_ptr++;
	count++;
	}
	format++;
}
    /* Write the buffer to the standard output */
    /* write_buffer(buffer, buffer_ptr);*/

va_end(args);

return (count);
}

