#include "lists.h"

/**
 * get_nodeint_at_index - get the nth node of listint_t linked list.
 * @head: Pointer to the head of the listint_t list.
 * @index: Index of the node to retrieve (starting from 0)
 *
 * Return: Pointer to the nthn node, or NULL if the node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count;

	if (head == NULL)
		return (NULL);
	for (count = 0; count < index; count++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}
