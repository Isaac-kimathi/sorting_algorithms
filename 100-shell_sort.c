#include "sort.h"

/**
 * int_swap - Swaps two integers in an array.
 * @u: The first int to swap.
 * @v: The second int to swap.
 */
void int_swap(int *u, int *v)
{
	int tmp;

	tmp = *u;
	*u = *v;
	*v = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: void
 * Description: Use of the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gp, x, y;

	if (array == NULL || size < 2)
		return;

	for (gp = 1; gp < (size / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (x = gp; x < size; x++)
		{
			y = x;
			while (y >= gp && array[y - gp] > array[y])
			{
				int_swap(array + y, array + (y - gp));
				y -= gp;
			}
		}
		print_array(array, size);
	}
}
