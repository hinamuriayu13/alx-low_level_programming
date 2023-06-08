#include "main.h"

/**
 * flip_bits - function counts the number of bits to be changed
 * to get from one number to the other
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to alter
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int exclusive = n ^ m;
    unsigned int count = 0;

    while (exclusive > 0)
    {
        if (exclusive & 1)
            count++;
        exclusive >>= 1;
    }

    return count;
}
