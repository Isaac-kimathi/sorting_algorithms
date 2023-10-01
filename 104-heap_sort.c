#include "sort.h"

/**
 * int_swap - Swap two integers in an array.
 * @g: The first integer to swapped.
 * @h: The second integer to be swapped.
 */
void int_swap(int *g, int *h)
{
	int tpr;

	tpr = *g;
	*g = *h;
	*h = tpr;
}

/**
 * bin_heap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @bs: index of the base row of the tree.
 * @rt: root node of the binary tree.
 */
void bin_heap(int *array, size_t size, size_t bs, size_t rt)
{
	size_t lt, rgt, hg;

	lt = 2 * rt + 1;
	rgt = 2 * rt + 2;
	hg = rt;

	if (lt < bs && array[lt] > array[hg])
		hg = lt;
	if (rgt < bs && array[rgt] > array[hg])
		hg = rgt;

	if (hg != rt)
	{
		int_swap(array + rt, array + hg);
		print_array(array, size);
		bin_heap(array, size, bs, hg);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: void
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		bin_heap(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		int_swap(array, array + x);
		print_array(array, size);
		bin_heap(array, size, x, 0);
	}
}
