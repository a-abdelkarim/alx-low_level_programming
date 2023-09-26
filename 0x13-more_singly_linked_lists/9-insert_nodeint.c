#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Insert a new node at a given postition in a list of type listint_t.
 * @head: Pointer to pointer of the head of the list
 * @idx: New node index
 * @n: int data to be stored in the new node
 *
 * Return: Adrress of the new node, or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *current, *new_node;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		current = *head;
		for (i = 0, i < idx - 1 && current != NULL; i++)
		{
			current = current->next;
		}
		if (current == NULL)
			return (NULL);
	}
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
