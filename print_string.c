#include "main.h"
#include <stddef.h>
#include <stdio.h>
/**
 * print_string - Prints a string to the standard output
 * @str: The string to be printed
 *
 * Return: The number of characters printed.
 */
<<<<<<< HEAD
int print_string(char *str)
{

	int count = 0;

	if (str == NULL)

	str = "(null)";


	while (*str)

	{
	_putchar(*str);
	count++;
	str++;
	}


return (count);
=======
int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
char *str = va_arg(types, char*);
int count = 0;
int i = 0;


if (str == NULL)
str = "(null)";

while (str[i] != '\0')
{
if (str[i] < ' ' || str[i] >= 127)
{
count += snprintf(buffer + count, BUFFER_SIZE - count, "\x%02X",
(unsigned char)str[i]);
}
else
{
buffer[count++] = str[i];
}
if (count >= BUFFER_SIZE - 1)
{
/* Buffer is full, write it to standard output */
write_buffer(buffer, count);
count = 0;
}
i++;
}
/* Write remaining characters in the buffer to standard output */
write_buffer(buffer, count);
return (i);
>>>>>>> 29a8469301045fc26f691b32e3ab81ad3395d398
}
