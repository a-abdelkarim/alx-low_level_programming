#include "lists.h"

/**
 * get_nodeint_at_index - get the nth node of listint_t linked list.
 * @head: Pointer to the head of the listint_t list.
 * @index: Index of the node to retrieve (starting from 0)
 *
 * Return: Pointer to the nthn node, or NULL if the node does not exist
 */

listint_t *get_nodeint_at_index(listnt_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		if (count == index)
			return (head);
		head = head->next;
		count++;
	}
	return (NULL);
}
