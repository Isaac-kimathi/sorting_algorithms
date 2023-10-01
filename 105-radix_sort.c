#include "sort.h"

/**
 * max_int - finds the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: maximum int in the array.
 */
int max_int(int *array, int size)
{
	int lg, x;

	for (lg = array[0], x = 1; x < size; x++)
	{
		if (array[x] > lg)
		lg = array[x];
	}

	return (lg);
}

/**
 * counting_rsort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sd: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void counting_rsort(int *array, size_t size, int sd, int *buffer)
{
	int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t n;

	for (n = 0; n < size; n++)
		cnt[(array[n] / sd) % 10] += 1;

	for (n = 0; n < 10; n++)
		cnt[i] += cnt[i - 1];

	for (n = size - 1; (int)n >= 0; n--)
	{
		buffer[cnt[(array[n] / sd) % 10] - 1] = array[n];
		cnt[(array[n] / sd) % 10] -= 1;
	}

	for (n = 0; n < size; n++)
		array[n] = buffer[n];
}
/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sd, *bffr;

	if (array == NULL || size < 2)
		return;

	bffr = malloc(sizeof(int) * size);
	if (buffr == NULL)
		return;

	max = max_int(array, size);
	for (sd = 1; max / sd > 0; sd *= 10)
	{
		counting_rsort(array, size, sd, buffr);
		print_array(array, size);
	}
	free(buffr);
}
