#include "sort.h"

/**
 * swap_ints - swaps two ints in array.
 * @a: first int to swap.
 * @b: second int to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts array of ints in asc order.
 * @array: array of ints to sort.
 * @size: size of array.
 *
 * Description: prints array on each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, ln = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (x = 0; x < ln - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_ints(array + x, array + x + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		ln--;
	}
}

