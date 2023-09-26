#include "lists.h"

/**
 * sum_listint - calculate the sum of all the data (n) of a listint_t linked list.
 * @head: pointer to the head of the listint_t
 *
 * Return: sum of all the data in the list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
