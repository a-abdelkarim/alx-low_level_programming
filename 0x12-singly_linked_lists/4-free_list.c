#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list to free
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	if (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
		free_list(head);
	}
}
