#include "main.h"
#include <stdio.h>  /* Include the <stdio.h> header for sprintf */
#include <string.h> /* Include the <string.h> header for strlen */

/**
 * handler - Handle conversion specifier
 *           based on length modifiers
 * @format: Format specifier string
 * @args: Arguments for the format specifier
 * @buffer: Buffer to store the converted string
 * @count: Pointer to the count of characters printed
 *
 * Return: The updated count of characters printed
 */
int handler(const char *format, va_list args, char *buffer, int *count)
{
/* Implementation code for handling each conversion specifier */
/* ... */

/* Convert num to string and store it in buffer */
if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
sprintf(buffer, "%d", num); /* Convert int to string */
*count += strlen(buffer);   /* Update the count */
}
else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
{
unsigned int num = va_arg(args, unsigned int);
sprintf(buffer, "%u", num); /* Convert unsigned int to string */
*count += strlen(buffer);   /* Update the count */
}
else if (*format == 'l')
{
long num = va_arg(args, long);
sprintf(buffer, "%ld", num); /* Convert long to string */
*count += strlen(buffer);    /* Update the count */
}
else if (*format == 'h')
{
short num = va_arg(args, int); /* Assuming short is promoted to int */
sprintf(buffer, "%d", num);    /* Convert int to string */
*count += strlen(buffer);      /* Update the count */
}

return (*count); /* Return the updated count */
}

