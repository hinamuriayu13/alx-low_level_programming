#include "main.h"

/**
 * binary_to_uint - function converts The  binary value to an unsigned int
 * @b: The String Containing The Binary Value
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int decimal_value = 0;

    if (b == NULL)
        return 0;

    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] != '0' && b[i] != '1')
            return 0;

        decimal_value = decimal_value * 2 + (b[i] - '0');
    }

    return decimal_value;
}
