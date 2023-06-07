/**
 * print_listint_safe - Prints a list safely.
 * @head: points to the head of the listint_t list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow, *fast;
    size_t count = 0;

    if (head == NULL)
        return 0;

    slow = head;
    fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            printf("Loop detected\n");
            return count;
        }
    }

    while (head)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        count++;
        head = head->next;
    }

    return count;
}
