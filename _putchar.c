#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * This function takes a character @c as input and writes it to
 *		the standard output.
 * It uses the write system call to perform the write operation.
 *
 * Return: On success, it returns the number of bytes
 *		written (always 1).
 *		On error, it returns -1.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

