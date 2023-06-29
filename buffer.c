#include "main.h"
#include <unistd.h>

/**
 * write_buffer - Writes the buffer to the standard output
 * @buffer: Buffer containing the data to write
 * @size: Size of the buffer
 *
 * Return: Number of characters written
 */
int write_buffer(char *buffer, int size)
{
    int total_written = 0;
    int bytes_written = 0;
    int bytes_remaining = size;

    while (bytes_remaining > 0)
    {
        bytes_written = write(1, buffer + total_written, bytes_remaining);
        if (bytes_written == -1)
        {
            /* Handle error */
            return (-1);
        }

        total_written += bytes_written;
        bytes_remaining -= bytes_written;
    }

    return (total_written);
}

