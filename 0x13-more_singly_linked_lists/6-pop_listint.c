#include "lists.h"
#include <stdlib.h>

/**
 *  po_listint - deletes the head node of a listint_t linked list.
 *  @head: Pointer
 *
 *  Return: Data (n) of the head node, or 0 if the list is empty.
 */
int pop_listint(listint_t, **head)
{
	listint_t *start;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	start = *head;
	n = tmp->n;
	*head = start->next;
	free(start);
	return (n);
}
