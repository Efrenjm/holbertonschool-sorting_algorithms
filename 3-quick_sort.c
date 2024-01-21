#include <stdio.h>
#include <stdio.h>
#include "sort.h"
/**
 * swap - swap two elements
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - make a slice of an initial array to compare its elements
 * @array: array to be sorted
 * @low: bottom element index
 * @high: top element index
 * @size: size of the array
 * Return: pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	i++;
	swap(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);
	return (i);
}
/**
 * quick_sort_helper - recursive section of the algorithm
 * @array: slice of the array to be compared
 * @low: index of the full array to be the bottom
 * @high: index of the full array to be the top
 * @size: size of the initial array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quick_sort_helper(array, low, pivot_index - 1, size);
		quick_sort_helper(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
