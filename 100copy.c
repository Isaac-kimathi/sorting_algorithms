#include "sort.h"

/**
 * int_swap - Swap two integers in an array.
 * @u: The first integer to swap.
 * @v: The second integer to swap.
 */
void int_swap(int *u, int *v)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *   order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, j;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				int_swap(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
