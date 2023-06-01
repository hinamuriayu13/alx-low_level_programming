#include <stdlib.h>

#include "lists.h"

/**
 * free_list - a function to free linked lists
 * @head: list_t is the list to be freed
 */
void free_list(list_t *head)
{
    list_t *temp;

    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}
