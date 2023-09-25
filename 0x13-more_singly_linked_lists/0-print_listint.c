#include "lists.h"
#include <stdio.h>

/**
 * print_linked_list - prints all the elements of a linked list of integers.
 *
 * @head: pointer to the head of the linked list
 *
 * Return: the number of nodes
 *
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        count++;
    }
    return (count);
}

