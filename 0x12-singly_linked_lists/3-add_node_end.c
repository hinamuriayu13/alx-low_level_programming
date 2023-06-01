#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - it adds a new node after the tail of a linked list )which will become the new tail)
 * @head: double pointer to list_t 
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node;
    list_t *temp = *head;
    unsigned int len = 0;

    while (str[len])
        len++;

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    new_node->len = len;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    while (temp->next)
        temp = temp->next;

    temp->next = new_node;

    return (new_node);
}
