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
size_t print_listint(const list_t *h)
{
    size_t count = 0;

    while (head != NULL)
    {
        printf("%d\n", h->data);
        h = h->next;
        count++;
    }
    return (count);
}

