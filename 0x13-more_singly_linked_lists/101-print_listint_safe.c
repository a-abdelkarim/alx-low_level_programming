#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list safely.
 *
 * @head: Pointer to the head of the list
 *
 * Return: Then number of the nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *loop_node = NULL;
	
	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;
		if (current->next >= loop_node)
		{
			loop_node = current->next;
		}
		else
		{
			printf("-> [%p] %d\n", (void *)current->next, current->next->n);
			break;
		}
		current = current->next;
	}
	return (count);
}
