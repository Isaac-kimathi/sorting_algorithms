#include "sort.h"

/**
 * intg_swap - swap two integers in an array
 * @x: the first integer to swap
 * @y: the second integer to swap
 */
void intg_swap(int *x, int *y)
{
	int prd;

	prd = *x;
	*x = *y;
	*y = prd;
}

/**
 * selection_sort - sort an array of integers in ascending order
 * using the selection sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 * return: void
 * Description: prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	size_t d, f;
	int *lss;

	if (array == NULL || size < 2)
		return;
	for (d = 0; d < size - 1; d++)
	{
		lss = array + d;
		for (f = d + 1; f < size; f++)
			lss = (array[f] < *lss) ? (array + f) : lss;
		if ((array + d) != lss)
		{
			intg_swap(array + d, lss);
			print_array(array, size);
		}
	}
}
