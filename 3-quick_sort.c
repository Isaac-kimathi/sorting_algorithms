#include "sort.h"

/**
 * intg_swap - swaps two integers in an array
 * @q: first integer to be swapped
 * @w: second integer to be swapped
 */
void intg_swap(int *q, int *w)
{
	int fx;

	fx = *q;
	*q = *w;
	*w = fx;
}

/**
 * lomuto_partition - partitioning an array into subarrays
 * @array: the array of integers
 * @sz: size of integer
 * @lw: the starting index of the subset to arrange
 * @up: the ending index of the subset to arrange
 * Return: integer
 */
int lomuto_partition(int *array, size_t sz, int lw, int up)
{
	int *pvt, rt, lft;

	pvt = array + up;
	for (rt = lft = lw; lft < up; lft++)
	{
		if (array[lft] < *pvt)
		{
			if (rt < lft)
			{
				intg_swap(array + lft, array + rt);
				print_array(array, sz);
			}
			rt++;
		}
	}

	if (array[rt] > *pvt)
	{
		intg_swap(array + rt, pvt);
		print_array(array, sz);
	}

	return (rt);
}

/**
 * sort_lomuto - recursive implementation of the quicksort algorithm.
 * @array: An array of integers to sort.
 * @sz: The size of the array.
 * @lw: The starting index of the array partition to arrange.
 * @up: The ending index of the array partition to arrange.
 * Return: void
 * Description: Uses the Lomuto partition scheme.
 */
void sort_lomuto(int *array, size_t sz, int lw, int up)
{
	int ns;

	if (up - lw > 0)
	{
		ns = lomuto_partition(array, sz, lw, up);
		sort_lomuto(array, sz, lw, ns - 1);
		sort_lomuto(array, sz, ns + 1, up);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @sz: The size of the array.
 * Return:void
 * Description: Uses the Lomuto partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort(int *array, size_t sz)
{
	if (array == NULL || sz < 2)
		return;

	sort_lomuto(array, sz, 0, sz - 1);
}
