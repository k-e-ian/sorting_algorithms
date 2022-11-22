#include "sort.h"

void swap_ints(int *int1, int *int2);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_partition_sort(int *array, size_t size, int left, int right);
/**
 * quick_sort - sorts array using quick sort algorith
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	/**lomuto partion scheme*/
	lomuto_partition_sort(array, size, 0, size - 1);
}

/**
 * lomuto_partition - order a partition of an array of integers
 * @array: array to be sorted
 * @size: size of array;
 * @left: starting index of partitioned array
 * @right: last index in partitioned array
 * Return: final partined index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;

	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_partition_sort - implement the quicksort algorithm
 * @array: array of ints
 * @size: size of array
 * @left: starting index of the partitioned array
 * @right: the ending index of the partitioned array
 * Return: void
 */
void lomuto_partition_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_partition_sort(array, size, left, partition - 1);
		lomuto_partition_sort(array, size, partition + 1, right);
	}
}

/**
 * swap_ints - swap two ints
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
