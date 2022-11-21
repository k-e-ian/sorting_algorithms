#include "sort.h"

void swap_nodes(listint_t **h, listint_t **num1, listint_t *num2);

/**
 * insertion_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: pointer to a pointer to doubly linked list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *count, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (count = (*list)->next; count != NULL; count = temp)
	{
		temp = count->next;
		insert = count->prev;
		while (insert != NULL && count->n < insert->n)
		{
			swap_nodes(list, &insert, count);
			print_list((const listint_t *)*list);
		}
	}
}

/**
 * swap_nodes - swap two nodes
 * @h: poiter to pointer to h
 * @num1: pointer to num1
 * @num2: pointer to num2
 * Retuen: void
 */
void swap_nodes(listint_t **h, listint_t **num1, listint_t *num2)
{
	(*num1)->next = num2->next;
	if (num2->next != NULL)
		num2->next->prev = *num1;
	num2->prev = (*num1)->prev;
	num2->next = *num1;
	if ((*num1)->prev != NULL)
		(*num1)->prev->next = num2;
	else
		*h = num2;
	(*num1)->prev = num2;
	*num1 = num2->prev;
}
