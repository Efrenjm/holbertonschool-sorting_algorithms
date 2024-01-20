#include "sort.h"

/**
  * bubble_sort - sorts an array of integers in ascending
  * order using the Bubble sort algorithm
  * @array: The array of integers to sort
  * @size: The size of the array of integers
  *
  * Return: Nothing
  */
void bubble_sort(int *array, size_t size)
{
	int i = 0, temp = 0, limit = 0, swap = 1;

	if (!array || size < 2)
		return;

	limit = size - 1;

	for (; i < limit; ++i)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			swap = 1;
			print_array(array, size);
		}

		if (swap == 1 && i == limit - 1)
			i = -1, swap = 0, --limit;
	}
}
