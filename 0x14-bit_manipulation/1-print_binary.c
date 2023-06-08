#include "main.h"

/**
 * print_binary -function  prints the binary value of a decimal number
 * @n:The  Number to be  Printed in binary
 */
void print_binary(unsigned long int n)
{
    if (n == 0)
    {
        _putchar('0');
        return;
    }

    if (n >> 1)
        print_binary(n >> 1);

    _putchar((n & 1) ? '1' : '0');
}
