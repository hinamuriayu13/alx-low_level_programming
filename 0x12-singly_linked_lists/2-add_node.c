#include <stdlib.h>
#include <string.h>

#include "lists.h"

/**
 * add_node - puts a new node at the beginning of the linked list
 * @head: double pointer to list_t 
 * @str: a new string to add in the node
 *
 * Return: the address of the new element, or 'NULL' in case it does not succeed  
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
    unsigned int len = 0;

    while (str[len])
        len++;

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    new_node->len = len;
    new_node->next = (*head);
    (*head) = new_node;

    return (*head);
}

