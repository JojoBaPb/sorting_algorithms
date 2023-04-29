#include "sort.h"

/**
 * get_max - gets max value in array of ints.
 * @array: array of ints.
 * @size: size of array.
 *
 * Return: max int of array.
 */
int get_max(int *array, int size)
{
	int max, x;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}

	return (max);
}

/**
 *  counting_sort - sorts array of ints in asc order
 * using counting sort algorithm.
 * @array: array of ints.
 * @size: size of array.
 *
 * Description: prints counting array.
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *sort, max, x;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(sort);
		return;
	}

	for (x = 0; x < (max + 1); x++)
		cnt[x] = 0;
	for (x = 0; x < (int)size; x++)
		cnt[array[x]] += 1;
	for (x = 0; x < (max + 1); x++)
		cnt[x] += cnt[x - 1];
	print_array(cnt, max + 1);

	for (x = 0; x < (int)size; x++)
	{
		sort[cnt[array[x]] - 1] = array[x];
		cnt[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sort[x];

	free(sort);
	free(cnt);
}
