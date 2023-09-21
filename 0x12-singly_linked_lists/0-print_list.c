#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 * @h: the list to print elements from
 *
 * Return: the number of Nodes
 */
size_t print_list(const list_t *h)
{
	size_t number_of_nodes;
	const list_t *current = h;

	if (current == NULL)
	{
		return (0);
	}

	number_of_nodes = 0;
	while (current)
	{
		if (current->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", current->len, current->str);
		}
		number_of_nodes++;
		current = current->next;
	}
	return (number_of_nodes);
}
