#include "lists.h"

/**
 * get_nodeint_at_index - function returns the node at a certain index in a linked list
 * @head: points to the head of the linked list
 * @index:the  index of the node to return
 *
 * Return: points to the node at the given index, or NULL if not found
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    listint_t *current = head;
    unsigned int count = 0;

    while (current != NULL)
    {
        if (count == index)
            return current;
        
        current = current->next;
        count++;
    }

    return NULL;
}
