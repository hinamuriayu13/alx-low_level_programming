#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: Double pointer to the list_t list
 * @str: New string to add in the node
 *
 * Return: The address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_elem;
    unsigned int len = 0;

    while (str[len])
        len++;

    new_elem = malloc(sizeof(list_t));
    if (new_elem == NULL)
        return (NULL);

    new_elem->str = strdup(str);
    if (new_elem->str == NULL)
    {
        free(new_elem);
        return (NULL);
    }

    new_elem->len = len;
    new_elem->next = *head;
    *head = new_elem;

    return (new_elem);
}
