#ifndef __SORT_H__
#define __SORT_H__

#include <stdlib.h>
#include <stdio.h>

/* Comparison direction macros for bitonic sort */
#define up 0
#define DOWN 1


/* Data Structure */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/* print_array */
void print_array(const int *array, size_t size);

/* print_list */
void print_list(const listint_t *list);

/* Swapping_function */
void swap_funct(int *a, int *b);
void swapper(listint_t *current, listint_t *current_old, listint_t **list);

/* task 0 */
void bubble_sort(int *array, size_t size);

/* task 1 */
void insertion_sort_list(listint_t **list);

/*task 2 */
void selection_sort(int *array, size_t size);

/* task 3 */
void quick_sort(int *array, size_t size);

/* task 4 */
void shell_sort(int *array, size_t size);

/* task 5 */
void cocktail_sort_list(listint_t **list);

/*task 6 */
void counting_sort(int *array, size_t size);

/* task 7 */
void merge_sort(int *array, size_t size);

/* task 8 */
void heap_sort(int *array, size_t size);

/* task 9 */
void radix_sort(int *array, size_t size);

/* task 10 */
void bitonic_sort(int *array, size_t size);

/* task 11 */
void quick_sort_hoare(int *array, size_t size);


#endif
