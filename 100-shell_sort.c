#include "sort.h"

/**
 * shell_sort - sorts int array in ascending order using shell sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void
 * Description: Knuth sequence
 */
void shell_sort(int *array, size_t size)
{
	/** knuth because is the knuth sequence, knuth variable = gap */
	size_t knuth, i, j;

	if (array == NULL || size < 2)
		return;

	for (knuth = 1; knuth < (size / 3); )
		knuth = knuth * 3 + 1;

	for ( ; knuth >= 1; knuth /= 3)
	{
		for (i = knuth; i < size; i++)
		{
			j = i;
			while (j >= knuth && array[j - knuth] > array[j])
			{
				swap_ints(array + j, array + (j - knuth));
				j -= knuth;
			}

		}
		print_array(array, size);
	}
}

/**
 * swap_ints - swap two ints in an array
 * @int1: first int pointer
 * @int2: second int pointer
 * Return: void
 */
void swap_ints(int *int1, int *int2)
{
	int temp;

	temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}
