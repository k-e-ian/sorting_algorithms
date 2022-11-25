#ifndef SORT_H
#define SORT_H

#include <sys/wait.h>

#include <stdlib.h>

#include <stdio.h>

#include <stdbool.h>

/**
 * struct listint_s - doubly linked list node
 * @n: integer stored in node
 * @prev: pointer to previous elemnt of the list
 * @next: pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);

void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);

void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);

void heap_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);

void quick_sort_hoare(int *array, size_t size);

void swap_ints(int *a, int *b);

#endif /* SORT_H */
