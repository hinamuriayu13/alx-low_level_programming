#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - 'singly linked list'
 * @str: string - (memory allocated for the string with 'malloc')
 * @len: length of the string
 * @next: pointer to the next node
 *
 * Description: Singly linked list node structure
 * for a Holberton project
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;

/**
 * print_list - Prints all the elements of a linked list
 * @h: Pointer to the head node of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_list(const list_t *h);

/**
 * list_len - returns the number of nodes in the  linked list
 * @h: Pointer to the head node of the list
 *
 * Return: The number of nodes in the list
 */
size_t list_len(const list_t *h);

/**
 * add_node - Adds a new node at the beginning of a linked list
 * @head: Pointer to the pointer to the head node of the list
 * @str: The string to be added to the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str);

/**
 * add_node_end - Adds a new node at the end of a linked list
 * @head: Pointer to the pointer to the head node of the list
 * @str: The string to be added to the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str);

/**
 * free_list -  Frees a linked list
 * @head: Pointer to the head node of the list
 */
void free_list(list_t *head);

#endif /* LISTS_H */
