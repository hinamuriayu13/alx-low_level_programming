#include "lists.h"
/**
 * sum_listint - returns the sum of all the data in a list
 * @head: points to the first node in the linked list
 *
 * Return: data values sum
 */
int sum_listint(listint_t *head)
{
    int sum = 0;
    listint_t *current = head;

    while (current != NULL)
    {
        sum += current->n;
        current = current->next;
    }

    return sum;
}
