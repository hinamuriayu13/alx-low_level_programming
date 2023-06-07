#include "lists.h"

/**
 * print_listint - function to print the elements of a linked list
 * @h: linked list to print
 *
 * Return:The Number Of Nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current)
	{
		printf("%d\n", current->n);
		count++;
		current = current->next;
	}

	return count;
}
