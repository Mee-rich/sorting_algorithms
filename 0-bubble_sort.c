#include "sort.h"


/**
 * bubble_sort - sorts an array
 * @array: array to be sorted
 * @size: array size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int holder;

	if (array == NULL)
		return;

	for (len = size; len > 0; len--)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				holder = array[i];
				array[i] = array[i + 1];
				array[i + 1] = holder;
				print_array(array, size);
			}
		}
	}
}
