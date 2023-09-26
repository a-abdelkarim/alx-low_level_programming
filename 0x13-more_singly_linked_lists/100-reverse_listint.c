#include "lists.h"

/**
 * reverse_listint - Reverse a linked list.
 * 
 * @head: Pointer to the pointer of the head of the list
 *
 * Return: A pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current != NULL)
	{
		listint_t *next_node = current->next;
		prev = current;
		current = next_node;
	}
	*head = prev;
	return (*head);
}
