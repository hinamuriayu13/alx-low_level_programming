#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: points to the list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
		return;

	while (*head)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}

	*head = NULL;
}
