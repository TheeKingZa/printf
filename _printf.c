#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;
	char buffer[BUFFER_SIZE] = {0};
	int flags = 0, width = 0, precision = -1, size = 0;

	va_start(args, format);

if (format == NULL)
	return (-1);

while (format && format[i])
{

if (format[i] == '%')
{

i++;
if (format[i] == '\0')
return (-1);

len += handle_print(format, &i, args, buffer, flags, width, precision, size);
flags = 0;
width = 0;
precision = -1;
size = 0;
}
else
{
buffer[len++] = format[i++];
if (len == BUFFER_SIZE)
{
write(1, buffer, len);
len = 0;
}
}
}

write(1, buffer, len);
va_end(args);

return (len);
}
