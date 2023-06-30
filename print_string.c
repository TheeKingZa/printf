#include "main.h"
#include <stddef.h>
#include <stdio.h>
/**
 * print_string - Prints a string to the standard output
 * @str: The string to be printed
 *
 * Return: The number of characters printed.
 */
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
}
