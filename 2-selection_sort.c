#include "sort.h"

/**
 * selection_sort - sort list with selection_sort
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp, swap_occurred;


	if (array == NULL || size < 2)
		return;
	
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		swap_occurred = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
				swap_occurred = 1;
			}
		}

		if (swap_occurred)
		{
			temp = array[min_index];
			array[min_index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
