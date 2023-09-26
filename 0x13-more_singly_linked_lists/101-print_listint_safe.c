#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _reallocate_list - reallocates memory for an array of pointers
 * to the nodes in a linked list
 * @old_list: the old list to append
 * @size: size of the new list (always one more than the old list)
 * @new: new node to add to the list
 *
 * Return: pointer to the new list
 */
const listint_t **_reallocate_list(const listint_t **old_list, size_t size, const listint_t *new_node)
{
	const listint_t **new_list;
	size_t i;

	new_list = malloc(size * sizeof(listint_t *));
	if (new_list == NULL)
	{
		free(old_list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
		new_list[i] = old_list[i];
	new_list[i] = new_node;
	free(old_list);
	return (new_list);
}

/**
 * print_listint_safe - Prints a list safely.
 *
 * @head: Pointer to the head of the list
 *
 * Return: Then number of the nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, num = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (i = 0; i < num; i++)
		{
			if (head == list[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (num);
			}
		}
		num++;
		list = _reallocate_list(list, num, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (num);
}
