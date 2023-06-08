#include "main.h"

/**
 * clear_bit - function sets the value of a given bit to 0
 * @n: points to the number to be changed
 * @index: index of the bit to be  cleared
 *
 * Return: 1 in case of  success, -1 in case of failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index > sizeof(unsigned long int) * 8 - 1)
        return (-1);

    *n &= ~(1UL << index);
    return (1);
}
