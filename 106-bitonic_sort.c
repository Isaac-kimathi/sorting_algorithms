#include "sort.h"

/**
 * int_swap - Swap two integers in an array.
 * @m: The first integer to swap.
 * @n: The second integer to swap.
 */
void int_swap(int *m, int *n)
{
	int tpr;

	tpr = *m;
	*m = *n;
	*n = tpr;
}

/**
 * bitonic_int - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @bgg: The starting index of the sequence in array to sort.
 * @sqnc: The size of the sequence to sort.
 * @flw: The direction to sort in.
 */
void bitonic_int(int *array, size_t size, size_t bgg, size_t sqnc,
				char flw)
{
	size_t x, skp = sqnc / 2;

	if (sqnc > 1)
	{
		for (x = bgg; x < bgg + skp; x++)
		{
			if ((flw == UP && array[x] > array[x + skp]) || 
				(flw == DOWN && array[x] < array[x + skp]))
				int_swap(array + x, array + x + skp);
		}
		bitonic_int(array, size, bgg, skp, flw);
		bitonic_int(array, size, bgg + skp, skp, flw);
	}
}

/**
 * seq_bitonic - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @bgg: The starting index of a block of the building bitonic sequence.
 * @sqnc: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void seq_bitonic(int *array, size_t size, size_t bgg, size_t sqnc, char flow)
{
	size_t slc = sqnc / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (sqnc > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sqnc, size, str);
		print_array(array + bgg, sqnc);

		seq_bitonic(array, size, bgg, slc, UP);
		seq_bitonic(array, size, bgg + slc, slc, DOWN);
		bitonic_int(array, size, bgg, sqnc, flow);

		printf("Result [%lu/%lu] (%s):\n", sqnc, size, str);
		print_array(array + bgg, sqnc);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	seq_bitonic(array, size, 0, size, UP);
}
