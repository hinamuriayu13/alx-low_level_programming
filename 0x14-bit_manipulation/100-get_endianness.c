#include "main.h"

/**
 * get_endianness -function  checks if a machine is little or big endian
 * Return: 0 or  1 , depends if it's big or little endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
