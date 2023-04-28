#include "sort.h"

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
 *  selection_sort - sorts array of ints in asc order
 * by using selection sort algorithm.
 * @array: array of ints.
 * @size: size of array.
 *
 * Description: prints array on each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *cas;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		cas = array + x;
		for (y = x + 1; y < size; y++)
			cas = (array[y] < *cas) ? (array + y) : cas;

		if ((array + x) != cas)
		{
			swap_ints(array + x, cas);
			print_array(array, size);
		}
	}
}
