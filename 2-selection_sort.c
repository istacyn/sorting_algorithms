#include "sort.h"

/**
 * swap - Swaps two elements in an integer array.
 * @x: A pointer to the first element.
 * @y: A pointer to the second element.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
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
	int *min_idx;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = array + i;
		for (j = i + 1; j < size; j++)
			min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;

		if ((array + i) != min_idx)
		{
			swap(array + i, min_idx);
			print_array(array, size);
		}
	}
}
