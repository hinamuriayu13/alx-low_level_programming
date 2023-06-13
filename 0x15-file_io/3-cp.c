#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if files can be opened.
 * @fFrom: file_from.
 * @fileTo: file_to.
 * @agmtvec: arguments vector.
 * Return: no return.
 */
void error_file(int fFrom, int fileTo, char *agmtvec[])
{
    if (fFrom == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", agmtvec[1]);
        exit(98);
    }
    if (fileTo == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", agmtvec[2]);
        exit(99);
    }
}

/**
 * main - check the code for Holberton School students.
 * @numargs: number of arguments.
 * @agmtvec: arguments vector.
 * Return: Always 0.
 */
int main(int numargs, char *agmtvec[])
{
    int fFrom, fileTo, err_close;
    ssize_t nchars, nwr;
    char buf[1024];

    if (numargs != 3)
    {
        dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
        exit(97);
    }

    fFrom = open(agmtvec[1], O_RDONLY);
    fileTo = open(agmtvec[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
    error_file(fFrom, fileTo, agmtvec);

    nchars = 1024;
    while (nchars == 1024)
    {
        nchars = read(fFrom, buf, 1024);
        if (nchars == -1)
            error_file(-1, 0, agmtvec);
        nwr = write(fileTo, buf, nchars);
        if (nwr == -1)
            error_file(0, -1, agmtvec);
    }

    err_close = close(fFrom);
    if (err_close == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fFrom);
        exit(100);
    }

    err_close = close(fileTo);
    if (err_close == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fFrom);
        exit(100);
    }
    return (0);
}
