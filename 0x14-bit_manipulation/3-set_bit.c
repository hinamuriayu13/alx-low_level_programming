#include "main.h"

/**
 * set_bit -function that  sets a bit at a given index to the value 1
 * @n: points to the number to be changed 
 * @index: index of the bit we want to change
 *
 * Return: 1 in case of  success, -1 in case of failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index > sizeof(unsigned long int) * 8 - 1)
        return (-1);

    *n |= (1UL << index);
    return (1);
}
