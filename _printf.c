#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Prints formatted output to stdout and returns
 *      the number of characters printed
 *      (excluding the null byte)
 * @format: A pointer to a constant character string
 *              representing the format specifier
 * @...: Additional arguments corresponding to the values referenced
 *              by the placeholders in the format string
 *
 * Return: The number of characters printed (excluding the null byte)
 *
 * Description: The format string is composed of
 *              zero or more directives.
 * The following conversion specifiers are handled:
 * - %c: Prints a single character.
 * - %s: Prints a null-terminated string.
 * - %%: Prints a single percent character.
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
/* Initialize a count variable number of characters printed */

while (*format)
{
if (*format == '%')
{
format++;
/* Move past the '%' */
if (
*format == 'c')
{
int c = va_arg(args, int);
/* Fetch the next argument as an int(byte(4) of int) */
count += _putchar(c);
/* Print the character and increment the count */
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
/* Fetch the next argument as a char pointer */
count += printf("%s", s);/* Print the string and increment the count */
}
else if (*format == '%')
{
count += _putchar('%');/* Print a percent character and increment the count */
}
}
else
{
count += _putchar(*format);
/* Print a regular character and increment the count */
}
format++;
/* Move to the next character in the format string */
}
va_end(args);
return (count);
}
