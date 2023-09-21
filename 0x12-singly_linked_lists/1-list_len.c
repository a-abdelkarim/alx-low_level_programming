#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: the linked list_t list
 *
 * Return: the number of elements in the linked list_t list
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;
	const list_t *current = h;

	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}
