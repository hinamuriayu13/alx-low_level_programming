#include "main.h"

/**
 * get_endianness -function  checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
    unsigned int i = 1;
    char *c = (char *) &i;

    if (*c)
        return 1; // Little Endian
    else
        return 0; // Big Endian
}
