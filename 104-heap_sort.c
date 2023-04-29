#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - swaps two ints in array.
 * @a: first int swap.
 * @b: second int swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turns binary tree into complete binary heap.
 * @array: array of ints of binary tree.
 * @size: size of array or tree.
 * @base: indx of base row in tree.
 * @root: root node of binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l1, r1, l2;

	l1 = 2 * root + 1;
	r1 = 2 * root + 2;
	l2 = root;

	if (l1 < base && array[l1] > array[l2])
		l2 = l1;
	if (r1 < base && array[r1] > array[l2])
		l2 = r1;

	if (l2 != root)
	{
		swap_ints(array + root, array + l2);
		print_array(array, size);
		max_heapify(array, size, base, l2);
	}
}

/**
 *  heap_sort - sorts array of ints in asc order
 * with heap sort algo.
 * @array: array of ints.
 * @size: size of array.
 *
 *  Description: Inits the sift-down heap sort
 * algorithm and prints array on each swap.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		max_heapify(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swap_ints(array, array + x);
		print_array(array, size);
		max_heapify(array, size, x, 0);
	}
}
