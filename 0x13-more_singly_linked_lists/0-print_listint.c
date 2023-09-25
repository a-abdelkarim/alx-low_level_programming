#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a listint_t list.
 *
 * @h: pointer to the head of the listint_t list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
    size_t count = 0; // Initialize count to 0

    while (h != NULL) // Traverse the linked list
    {
        printf("%d\n", h->n); // Print the value of the current node
        h = h->next; // Move to the next node
        count++; // Increment the count
    }

    return (count); // Return the number of nodes
}

