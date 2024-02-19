#include "sort.h"

/**
 * max_num - max value in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: returns the maximum integer in the array
 */
int max_num(int *array, int size)
{
	int maxx, j;

	maxx = array[0];
	for (j = 1; j < size; j++)
		if (array[j] > maxx)
			maxx = array[j];
	return (maxx);
}

/**
 * counting_sort - The counting algorithm is used to sort the algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int maxx, j, *count, *sorted;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxx = max_num(array, size);
	count = malloc(sizeof(int) * (maxx + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (maxx + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (maxx + 1); j++)
		count[j] += count[j - 1];

	print_array(count, maxx + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];
	
	free(sorted);
	free(count);
}
