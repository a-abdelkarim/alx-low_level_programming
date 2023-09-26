#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Delete the node at given index.
 *
 * @head: Pointer to the pointer of the head of the list
 * @index: Index of the node to be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *tmp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
		return (1);
	}
	current = *head;
	for (i = 0; i < index - 1 && current != NULL; i++)
		current = current->next;
	if (current == NULL || current->next == NULL)
		return (-1);
	tmp = current->next;
	current->next = tmp->next;
	free(tmp);
	return (1);
}
