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
 *  shell_sort - sorts array of ints in asc order
 * using shell sort algorithm.
 * @array: array of ints.
 * @size: size of array.
 *
 * Description: Uses Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t breaK, x, y;

	if (array == NULL || size < 2)
		return;

	for (breaK = 1; breaK < (size / 3);)
		breaK = breaK * 3 + 1;

	for (; breaK >= 1; breaK /= 3)
	{
		for (x = breaK; x < size; x++)
		{
			y = x;
			while (y >= breaK && array[y - breaK] > array[y])
			{
				swap_ints(array + y, array + (y - breaK));
				y -= breaK;
			}
		}
		print_array(array, size);
	}
}
