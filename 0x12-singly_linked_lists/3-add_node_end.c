#include "lists.h"
#include <stdio.h>

/**
 * _strlen - returns the number of characters in a string
 * @str: string
 *
 * Return: number of characters
 */
unsigned int _strlen(const char *str)
{
	unsigned int len = 0;

	if (str)
	{
		while (str[len] != '\0')
		{
			len++;
		}
	}
	return (len);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to the head of the list
 * @str: string to add
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *last_node;
	list_t *new;

	new = malloc(sizeof(list_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	last_node = *head;
	while (last_node->next)
	{
		last_node = last_node->next;
	}

	last_node->next = new;
	return (last_node);
}
