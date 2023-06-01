#include <stdio.h>
#include "lists.h"

size_t print_list(const list_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("[%u] %s\n", h->len, (h->str == NULL ? "(nil)" : h->str));
        h = h->next;
        count++;
    }

    return count;
}
