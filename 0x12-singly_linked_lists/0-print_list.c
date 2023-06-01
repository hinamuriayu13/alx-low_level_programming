#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints the elements of linked lists
 * @h: Pointer to the list_t (the list to be printed )
 *
 * Return: The number of nodes 
 */
size_t print_list(const list_t *h)
{
    size_t nodes_printed = 0;

    while (h)
    {
        if (!h->str)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", h->len, h->str);
        
        h = h->next;
        nodes_printed++;
    }

    return nodes_printed;
}
