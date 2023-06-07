#include "lists.h"
/**
 * delete_nodeint_at_index - function deletes a node in a linked list at a certain index
 * @head: points to the pointer to the first element in the list
 * @index: the index of the node to be  deleted
 *
 * Return: 1 for Success and  -1 for Fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp, *prev;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return -1;

    if (index == 0)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    temp = *head;
    for (i = 0; i < index && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return -1;

    prev->next = temp->next;
    free(temp);

    return 1;
}
