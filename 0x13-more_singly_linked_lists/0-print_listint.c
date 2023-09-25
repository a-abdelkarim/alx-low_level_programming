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
size_t print_listint(const list_t *head)
{
    size_t count = 0;

    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
        count++;
    }
    return (count);
}

