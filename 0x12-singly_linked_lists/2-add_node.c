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
    if (str == NULL)
        return NULL;

    // Allocate memory for the new node
    list_t *new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return NULL;

    // Duplicate the string using strdup
    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return NULL;
    }

    // Set the length of the string
    new_node->len = strlen(str);

    // Update the next pointer to point to the previous head
    new_node->next = *head;

    // Update the head to point to the new node
    *head = new_node;

    return new_node;
}
