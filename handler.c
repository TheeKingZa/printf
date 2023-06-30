#include "main.h"

/**
 * handle_integer - Handles the 'd' and 'i' conversion specifiers
 * @args: The va_list containing the arguments
 * @buffer: The buffer to store the output string
 * @count: A pointer to the count of characters printed
 *
 * Return: The number of characters printed
 */
int handle_integer(va_list args, char *buffer, int *count)
{
    int num = va_arg(args, int);

    return (print_integer(num, buffer + *count));
}

/**
 * handle_unsigned_integer - Handles the 'u' conversion specifier
 * @args: The va_list containing the arguments
 * @buffer: The buffer to store the output string
 * @count: A pointer to the count of characters printed
 *
 * Return: The number of characters printed
 */
int handle_unsigned_integer(va_list args, char *buffer, int *count)
{
    unsigned int num = va_arg(args, unsigned int);

    return (print_unsigned_integer(num, buffer + *count));
}

/* Add similar helper functions for other conversion specifiers */

typedef struct {
    char specifier;
    int (*handler)(va_list args, char *buffer, int *count);
} ConversionHandler;

/**
 * get_conversion_handler - Retrieves the appropriate conversion handler
 * for a given specifier
 * @specifier: The conversion specifier
 *
 * Return: Pointer to the conversion handler function
 */
int (*get_conversion_handler(char specifier))(va_list, char *, int *);
int (*get_conversion_handler(char specifier))(va_list, char *, int *)
{
    static ConversionHandler conversionHandlers[] = {
        {'d', handle_integer},
        {'i', handle_integer},
        {'u', handle_unsigned_integer},
        /* Add entries for other conversion specifiers */
    };

    int numHandlers = sizeof(conversionHandlers) / sizeof(conversionHandlers[0]);

    for (int i = 0; i < numHandlers; i++)
    {
        if (conversionHandlers[i].specifier == specifier)
        {
            return conversionHandlers[i].handler;
        }
    }

    return NULL;
}

/**
 * handler - Handles the format specifiers and builds the output string
 * @format: The format string
 * @args: The va_list containing the arguments
 * @buffer: The buffer to store the output string
 * @count: A pointer to the count of characters printed
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int handler(const char *format, va_list args, char *buffer, int *count)
{
    int i, j;
    char *str;

    i = 0;
    j = 0;

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;

            int (*conversionHandler)(va_list, char *, int *);
            conversionHandler = get_conversion_handler(format[i]);

            if (conversionHandler != NULL)
            {
                j += conversionHandler(args, buffer, count);
            }
            else
            {
                buffer[j++] = '%';
                buffer[j++] = format[i];
            }
        }
        else
        {
            buffer[j++] = format[i];
        }

        i++;
    }

    *count = j;
    buffer[j] = '\0';
    return j;
}

