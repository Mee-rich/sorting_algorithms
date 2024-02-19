#include "sort.h"

/**
 * max_num - function to get the max value in
 * array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: returns the maximum integer in the array
 */
int max_num(int *array, int size)
{
	int max = array[0];
	int i;
	
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * countSort- Sort the significant digits of an array of integers
 * in ascending order using Counting algorithm
 * @array: AN array of integers
 * @size: The size of the array
 * @exp: counting sort for each digit place
 */
void countSort(int *array, size_t size, int exp)
{
	int i;
	/* Radix (base) is for decimal numbers */
	const int base = 10;
	
	int output[10]; /* output array size */
	int count[10];

	/* Initialize the count array */
	for (i = 0; i < base; i++)
		count[i] = 0;

	/*Count the occurences of digits at the specified place*/
	for (i =0; i < (int)size; i++)
		count[(array[i] / exp) % base]++;

	for (i = 1; i <  base; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % base] - 1] = array[i];
		count[(array[i] / exp) % base]--;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}
}

/**
 * radix_sort - function that sorts an array of integers in 
 * ascending order 
 * @array: array containing only numbers > 0
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = max_num(array, size);
	int exp;

	if (array == NULL || size < 2)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
