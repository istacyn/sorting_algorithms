#include "sort.h"

/**
 * swap - Swaps two elements in an integer array.
 * @x: A pointer to the first element.
 * @y: A pointer to the second element.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *		using the Selection sort algorithm
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = 1;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
