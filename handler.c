#include "main.h"
#include <stdio.h>  /* Include the <stdio.h> header for sprintf */
#include <string.h> /* Include the <string.h> header for strlen */

/**
 * handler - Handle conversion specifier based on length modifiers
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
else if (*format == 'S')
{
char *str = va_arg(args, char *);
int i, j = 0;
char temp[5]; /* Store the \xHH representation */

for (i = 0; str[i] != '\0'; i++)
{
if (isprint((unsigned char)str[i])) /* Check if printable */
{
buffer[j++] = str[i];
*count += 1;
}
else
{
sprintf(temp, "\\x%02X", (unsigned char)str[i]);
strcat(buffer, temp);
j += 4;
*count += 4;
}
}
}
else if (*format == 'p')
{
void *ptr = va_arg(args, void *);
uintptr_t address = (uintptr_t)ptr;
sprintf(buffer, "%p", (void *)address);
*count += strlen(buffer);
}
else if (*format == 'd' || *format == 'i')
{

int num = va_arg(args, int);
char format_str[10];

sprintf(format_str, "%%%c%s", *format, "+");
sprintf(buffer, format_str, num);
*count += strlen(buffer);
}
else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
{
unsigned int num = va_arg(args, unsigned int);
char format_str[10];

sprintf(format_str, "%%%c%s", *format, "+");
sprintf(buffer, format_str, num);
*count += strlen(buffer);
}
else if (*format == 'f' || *format == 'F')
{
double num = va_arg(args, double);
char format_str[10];

sprintf(format_str, "%%%c%s", *format, "+");
sprintf(buffer, format_str, num);
*count += strlen(buffer);
}
else if (*format == 'g' || *format == 'G')
{
double num = va_arg(args, double);
char format_str[10];

sprintf(format_str, "%%%c%s", *format, "+");
sprintf(buffer, format_str, num);
*count += strlen(buffer);
}
else if (*format == 'e' || *format == 'E')
{
double num = va_arg(args, double);
char format_str[10];

sprintf(format_str, "%%%c%s", *format, "+");
sprintf(buffer, format_str, num);
*count += strlen(buffer);
}
else if (*format == 'x' || *format == 'X')
{
unsigned int num = va_arg(args, unsigned int);
char format_str[10];

sprintf(format_str, "%%%c%s", *format, "#");
sprintf(buffer, format_str, num);
*count += strlen(buffer);
}
else if (*format == 'p')
{
void *ptr = va_arg(args, void *);
uintptr_t address = (uintptr_t)ptr;
sprintf(buffer, "%#lx", (unsigned long)address);
*count += strlen(buffer);
}

return (*count); /* Return the updated count */
}
