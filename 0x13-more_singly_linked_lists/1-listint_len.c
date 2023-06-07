#include "lists.h"

/**
 * listint_len - function that returns the number of elements in a linked list
 * @h: linked list to traverse
 *
 * Return: The Number Of Nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current)
	{
		count++;
		current = current->next;
	}

	return count;
}
