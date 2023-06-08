#include "main.h"
#include <unistd.h>
/**
 * _putchar - function to write the char c to stdout
 * @c: character to be printed
 *
 * Return: in case of success result : 1.
 * in case of error it returns  -1 .
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

