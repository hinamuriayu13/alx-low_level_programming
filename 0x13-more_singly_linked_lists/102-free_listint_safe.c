/**
 * free_listint_safe - Function frees a linked list
 * @h: Points to start of the linked list
 *
 * Return:Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *current, *next;

    if (h == NULL || *h == NULL)
        return 0;

    current = *h;
    next = current->next;
    current->next = NULL;

    while (current != NULL)
    {
        count++;
        free(current);
        current = next;

        if (current != NULL)
            next = current->next;
    }

    *h = NULL;

    return count;
}
