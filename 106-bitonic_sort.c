#include "sort.h"

/**
 * swap_function - swaps two integer in 
 * an array using a temp storage
 * @a: The first integer
 * @b: The second integer
 */
void swap_function(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * merge - Sort a bitonic sequence inside an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * @start: The first index of the sequence in array to sort
 * @seq: The size of the sequence to sort
 * @flow: Direction to sort
 */
void merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == 'U' && array[i] > array[i + jump]) ||
			    (flow == 'D' && array[i] < array[i + jump]))
			{
				swap_function(array + i, array + i + jump);
			}
		}
		merge(array, size, start, jump, flow);
		merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sequence - Convert an array of integers to a bitonic sequence
 * @array: An array of integers
 * @size: The size of the array
 * @start: The first index of a block of the building bitonic sequence
 * @seq: The size of a block of the building bitonic sequence
 * @flow: The direction of the bitonic sequence
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t space = seq / 2;
	char *str = (flow == 'U') ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_sequence(array, size, start, space, 'U');
		bitonic_sequence(array, size, start + space, space, 'D');
		merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);

		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - function that sorts an array on integers in 
 * ascending order using the bitonic sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * Description: Prints each array after each swap
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sequence(array, size, 0, size, 'U');
}

