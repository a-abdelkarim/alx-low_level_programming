#include "lists.h"

/**
 * _strlen - returns the number of characters in a string
 * @str: string
 *
 * Return: number of characters
 */
int _strlen(const char *str)
{
	int len = 0;

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
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the pointer to the head of the list
 * @str: string
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = *head;
	*head = new;
	return (*head);
}
