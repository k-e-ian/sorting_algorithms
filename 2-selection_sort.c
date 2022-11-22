#include "sort.h"

void swap_ints(int *int1, int *int2);
/**
 * selection_sort - sorts array of ints with selction sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *small;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small = array + i;
		for (j = i; j < size; j++)
			small = (array[j] < *small) ? (array + j) : small;

		if ((array + i) != small)
		{
			swap_ints(array + i, small);
			print_array(array, size);
		}
	}
}

/**
 * swap_ints - swaps two ints in an array
 * @int1: pointer to first int
 * @int2: pointer to second int
 * Return: void
 */
void swap_ints(int *int1, int *int2)
{
	int temp;

	temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}
