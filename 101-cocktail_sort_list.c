#include "sort.h"

/**
 * cocktail_sort_list - sort a listint_t doubly linked list of ints in
 *			ascending order using cocktail shaker algorithm
 * @list: a pointer to the head of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool power_shake = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL; )
		tail = tail->next;

	while (power_shake == false)
	{
		power_shake = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				power_shake = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				power_shake = false;
			}
		}
	}
}

/**
 * swap_node_behind - swap node in a doubly linke list with the node behind
 * @list: pointer to pointer to list head in doubly linked list
 * @tail: pointer to tail of the doublylinked list
 * @shaker: a pointer to the current swapping node of algorithm
 * Return: void
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * swap_node_ahead - swap node in doubly linked list with node ahead
 * @list: pointer to pointer to list head in doubly linked list
 * @tail: pointer to tail in doubly linked list
 * @shaker: pinter to the current swapping node of the algorithm
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}
