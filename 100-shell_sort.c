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
 * shell_sort - Sorts an array of integers in ascending order
 *	using the Shell sort algorithm, using the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
