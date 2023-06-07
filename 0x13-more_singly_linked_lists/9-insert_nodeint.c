/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a position set by the index given
 * @head: points to the pointer to thestart  of the list
 * @idx: index where the new node will be inserted
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL if the operation fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i;
    listint_t *new;
    listint_t *temp;

    if (head == NULL)
        return NULL;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return NULL;

    new->n = n;
    new->next = NULL;

    if (idx == 0)
    {
        new->next = *head;
        *head = new;
        return new;
    }

    temp = *head;
    for (i = 0; temp != NULL && i < idx - 1; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        free(new);
        return NULL;
    }

    new->next = temp->next;
    temp->next = new;

    return new;
}
