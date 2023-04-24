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
 * partition - Partitions the array using Lomuto scheme.
 * @array: The array to be sorted.
 * @start: The starting index of the partition to be sorted.
 * @end: The ending index of the partition to be sorted.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 */
int partition(int *array, int start, int end, size_t size)
{
	int *pivot, i, j;

	pivot = array + end;
	for (i = j = start; j < end; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * recursive_sort - Sorts the array usng recursion and Lomuto partition.
 * @array: The array to be sorted.
 * @start: The starting index of the partition to be sorted.
 * @end: The ending index of the partition to be sorted.
 * @size: The size of the array.
 */
void recursive_sort(int *array, int start, int end, size_t size)
{
	int pi;

	if (end - start > 0)
	{
		pi = partition(array, start, end, size);
		recursive_sort(array, start, pi - 1, size);
		recursive_sort(array, pi + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *		using the Quick sort algorithm.
 *  @array: The array to be sorted.
 *  @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_sort(array, 0, size - 1, size);
}
