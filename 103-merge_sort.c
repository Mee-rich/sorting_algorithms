#include "sort.h"

/**
 * print_left_right - This prints the left and right partition
 * @array: array
 * @size: size of second array
 * @first: initial position
 * @mid: middle position
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int j;

	printf("Merging...\n");
	printf("[left]: ");
	j = first;

	while (j < mid)
	{
		if (j != mid - 1)
			printf("%d, ", array[j]);
		else
			printf("%d\n", array[j]);
		j++;
	}

	printf("[right]: ");
	j = mid;
	while (j < size)
	{
		if(j < size - 1)
			printf("%d, ", array[j]);
		else
			printf("%d\n", array[j]);
		j++;
	}
}

/**
 * merge - merge the values in the podition of array
 * @array: first array
 * @size: size of second array
 * @cpy: copy of array
 * @first: initial position
 * @mid: middle position
 */
void merge(int *array, int size, int first, int mid, int *cpy)
{
	int m, n, o;

	print_left_right(array, size, first, mid);

	m = first;
	n = mid;

	printf("[Done] : ");
	o = first;
	while (o < size)
	{
		if (m < mid && (n >= size || array[m] <= array[n]))
		{
			cpy[o] = array[m];
			m++;
		}
		else
		{
			cpy[o] = array[n];
			n++;
		}
		if (o < size - 1)
			printf("%d, ", cpy[o]);
		else
			printf("%d\n", cpy[o]);
		o++;
	}
}

/**
 * mergeSort - An array seperator
 * @cpy: array copy
 * @first: The initial position
 * @size: size of the original array
 * @array: The original array
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int mid;

	if (size - first < 2)
		return;
	
	mid = (size + first) / 2;

	mergeSort(array, first, mid, cpy);
	mergeSort(array, mid, size, array);

	merge(cpy, size, first, mid, array);
}

/**
 * copy_arr - copy array of int
 * @arr: array source
 * @cpy: array destination
 * @size: array size
 */
void copy_array(int *arr, int *cpy, int size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		cpy[i] = arr[i];
}

/**
 * merge_sort - create partition and copy
 * @array: array
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;

	cpy = malloc(sizeof(int) * size - 1);

	if (cpy == NULL)
		return;
	copy_array(array, cpy, size);

	mergeSort(cpy, 0, size, array);
	free(cpy);
}
