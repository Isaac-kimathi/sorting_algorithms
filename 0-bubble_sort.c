#include "sort.h"

/**
 *intg_swap - Swap two integers in an array.
 * @q: The first integer to swap.
 * @w: The second integer to swap into it place
 */
void intg_swap(int *q, int *w)
{
	int temp;

	temp = *q;
	*q = *w;
	*w = temp;
}

/***
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * Description: Prints the array after each swap occurs
 * @array: An array of integers to sort
 * @size: The size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t x = 0, sp;
	bool sort = false;

	if (array == NULL || size <= 1)
		return;

	sp = size;
	while (sort == false)
	{
		sort = true;
		for (; x < sp - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				intg_swap(array + x , array + x + 1);
				print_array(array, size);
				sort = false;
			}
		}
		sp--;
	}
}
