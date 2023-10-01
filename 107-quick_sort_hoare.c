#include "sort.h"

/**
 * int_swap - Swap two integers in an array.
 * @c: The first integer to swap.
 * @d: The second integer to swap.
 */
void int_swap(int *c, int *d)
{
	int tpr;

	tpr = *c;
	*c = *d;
	*d = tpr;
}

/**
 * hoare_partition_sch - Order a subset of an array of integers
 *  according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @lt: The starting index of the subset to order.
 * @rgt: The ending index of the subset to order.
 *
 * Return: The final partition index.
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition_sch(int *array, size_t size, int lt, int rgt)
{
	int pvt, abv, blw;

	pvt = array[rgt];
	for (abv = lt - 1, blw = rgt + 1; abv < blw;)
	{
		do {
			abv++;
		} while (array[abv] < pvt);
		do {
			blw--;
		} while (array[blw] > pvt);

		if (abv < blw)
		{
			int_swap(array + abv, array + blw);
			print_array(array, size);
		}
	}
	return (abv);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lt: The starting index of the array partition to order.
 * @rgt: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int lt, int rgt)
{
	int pt;

	if (rgt - lt > 0)
	{
		pt = hoare_partition_sch(array, size, lt, rgt);
		hoare_sort(array, size, lt, pt - 1);
		hoare_sort(array, size, pt, rgt);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: void
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
