#include "main.h"

/**
 * get_bit - function returns the value of a bit at an index within a decimal number
 * @n: number to look for 
 * @index: index of the bit to return
 *
 * Return: value of the bit at the specified index
 */
int get_bit(unsigned long int n, unsigned int index)
{
    if (index > sizeof(unsigned long int) * 8 - 1)
        return (-1);

    return ((n >> index) & 1);
}
