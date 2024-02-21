#include "sort.h"

/**
 * swap_function - function to swap two integers in an
 * array using a temp storage
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
 * partition - Order a subset of an array of integers 
 * in accordance to the hoare partition scheme
 * @array: The array of integers
 * @size: The size of the array
 * @left: The first index of the subset
 * @right: The last index of the subset
 * Return: returns the final partition index
 * Description: Prints the array after each swap of two elements
 */
int partition(int *array, size_t size, int left, int right)
{
	int pivot, top, bottom;

	pivot = array[right];
	for (top = left - 1, bottom = right - 1; top < bottom;)
	{
		do {
			top ++;
		} while (array[top] < pivot);
		do {
			bottom--;
		} while (array[bottom] > pivot);

		if (top < bottom)
		{
			swap_function(array + top, array + bottom);
			print_array(array, size);
		}
	}
	return (top);
}

/**
 * sort - Quicksort algorithm using recursion
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The first index of the array partition to order
 * @right: The last index of the array partition to order
 * Description: USes the Hoare partition scheme
 */
void sort(int *array, size_t size, int left, int right)
{
	int space;

	if (right - left > 0)
	{
		space = partition(array, size, left, right);
		sort(array, size, left, space - 1);
		sort(array, size, space, right);
	}
}

/**
 * quick_sort_hoare -m  function that sorts an array of integers in
 * ascending order using the quick sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * Description: Prints the array after each swp of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, size, 0, size - 1);
}
