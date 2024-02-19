#include "sort.h"

#define getParent(i) (((i) - 1) / 2)
#define getLeft(i) (2 * (i) + 1)
#define getRight(i) (2 * (i) + 2)

/**
 * swap - function to swap two elements in an array
 * @a: first element
 * @b: second element
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Function to perform the sift down
 * operation in the heap
 * @array: The heap array
 * @size: size of the array
 * @index: index node of the heap
 * @end: The element sifted to the end
 */
void sift_down(int *array, size_t index, size_t end)
{
	size_t largest, left, right;

	do {
		left = getLeft(index);
		right = getRight(index);
		largest = index;

		if (right < end && array[right] > array[largest])
			largest = right;
		if (left < end && array[left] > array[largest])
			largest = left;

		if (index == largest)
			return;

		swap(&array[index], &array[largest]);
		index = largest;
	} while (getLeft(index) < end);
}

/**
 * build_heap - Function to build a max heap from the array
 * @array: The array to build a heap from
 * @size: The size of the array
 */
void build_heap(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = getParent(size - 1); i != (size_t)-1; i--)
	{
		sift_down(array, i, size);
		print_array(array, size);
	}
}

/**
 * heap_sort - Heap sort function
 * @array: Thearray to sort
 * @size: The size of @array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	build_heap(array, size);

	for (i = (int)size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		sift_down(array, 0, i);
	}
}
