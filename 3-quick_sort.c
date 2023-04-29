#include "sort.h"

void swap_ints(int *a, int *b);
void quick_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);

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
 *  lomuto_partition - order subset of array of ints based on
 * the lomuto partition scheme (with last element as pivot).
 * @array: array of ints.
 * @size: size of array.
 * @left: starting indx of subset on order.
 * @right: last indx of subset on order.
 *
 * Return: final partition indx.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, bot;

	pivot = array + right;
	for (top = bot = left; bot < right; bot++)
	{
		if (array[bot] < *pivot)
		{
			if (top < bot)
			{
				swap_ints(array + bot, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swap_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - ini quicksort algorithm.
 * @array: array of ints to sort.
 * @size: size of array.
 * @left: starting indx of array partition in order.
 * @right: last indx of array partition in order.
 *
 * Description: uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part9n;

	if (right - left > 0)
	{
		part9n = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part9n - 1);
		lomuto_sort(array, size, part9n + 1, right);
	}
}

/**
 *  quick_sort - sorts array of ints in asc order
 * with quicksort algorithm.
 * @array: array of ints.
 * @size: size of array.
 *
 *  Description: uses Lomuto partition scheme and prints
 * array on each swap of two elems.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
