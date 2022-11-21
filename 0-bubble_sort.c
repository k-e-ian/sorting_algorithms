#include "sort.h"

/**
 * bubble_sort - sorts an array of ints in ascending order using Bubble Sort
 * @array: array of ints to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubble_up = false;

	if (array == NULL || size < 2)
		return;

	while (bubble_up == false)
	{
		bubble_up = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubble_up = false;
			}
		}
		len--;
	}
}

/**
 * swap_ints - swap two ints in an array
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
